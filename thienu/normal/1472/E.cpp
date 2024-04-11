#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int get_ans(int x, int y, int n, vector<pii> &pref, vector<pair<pii, int>> &points){
    // binary search for less than x
    int left = -1, right = 2 * n - 1;
    while(left < right){
        int mid = left + (right - left + 1) / 2;
        if(points[mid].first.first < x){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }

    if(left == -1) return -1;

    int min_pos, mini;
    tie(mini, min_pos) = pref[left];

    if(min_pos == -1) return -1;

    debug(x, y, left, min_pos, mini);

    if(mini >= y) return -1;
    return points[min_pos].second;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<pii, int>> points(2 * n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points[2*i] = {{x, y}, i};
        points[2*i+1] = {{y, x}, i};
    }

    auto orig = points;

    sort(points.begin(), points.end());

    debug(points);

    vpii pref(2 * n); // min, pos
    pref[0] = {1e9 + 7, -1};
    for(int i = 1; i < 2 * n; i++){
        if(points[i].first.second < pref[i-1].first){
            pref[i] = {points[i].first.second, i};
        }
        else{
            pref[i] = pref[i-1];
        }
    }

    debug(pref);

    for(int i = 0; i < n; i++){
        int x, y;
        tie(x, y) = orig[2 * i].first;

        int a = get_ans(x, y, n, pref, points);
        int b = get_ans(y, x, n, pref, points);
        if(a == -1 && b == -1){
            cout << "-1 ";
        }
        else{
            cout << max(a, b) + 1 << " ";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}