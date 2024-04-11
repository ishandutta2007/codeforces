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

int N = 200;

int query(int d){
    vpii pts;
    for(int i = d; i <= N; i+=d){
        for(int j = 1; j <= N; j++){
            pts.push_back({i, j});
        }
    }
    cout << "? " << pts.size() << endl;
    for(auto p : pts){
        cout << p.first << ' ' << p.second << ' ';
    }
    cout << endl;
    debug(d, pts.size());
    int x;
    cin >> x;
    return x;
}

void solve(){
    vi cache(9);
    int area = query(1);
    cache[0] = area;
    int ans = 0;
    for(int add = 4; add; add>>=1){
        int mid = ans+add;
        int res = query(1<<mid);
        cache[mid] = res;
        if(res * (1<<mid) == area){
            ans = mid;
        }
    }
    debug(ans);
    int bad_area = cache[ans+1] * (1<<(ans+1));
    int width = abs(bad_area - area) / (1<<ans);
    int height = area / width;
    debug(bad_area, width, height);
    cout << "! " << 2*(width + height) - 4 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}