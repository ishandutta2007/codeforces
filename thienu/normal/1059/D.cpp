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
 
double INF = 2e18;
 
double eps = 1e-10;
 
void solve(){
    int n;
    cin >> n;
    vpii points;
    bool pos = false, neg = false;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
        if(y > 0) pos = true;
        else neg = true;
    }
    if(pos && neg){
        cout << -1 << endl;
        return;
    }
    else if(neg){
        for(int i = 0; i < n; i++){
            points[i] = {points[i].first, -points[i].second};
        }
    }
    sort(points.begin(), points.end());
    debug(points);
    
    double ans = 0;
    for(double add = 5e17; add > eps; add /= 2){
        double mid = add + ans;
        bool good = true;
        double left = -INF;
        double right = INF;
        for(int i = 0; i < n; i++){
            double d = abs(mid - points[i].second);
            if(d > mid){
                good = false;
                break;
            }
            double deviation = sqrt(mid * mid - d * d);
            left = max(left, points[i].first - deviation);
            right = min(right, points[i].first + deviation);
        }
        if(!good || left > right){
            ans = mid;
        }
        debug(mid, left, right, good);
    }
    printf("%.09f\n", ans);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}