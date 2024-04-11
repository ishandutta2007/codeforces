#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

tuple<int, int, int> line(int x1, int x2, int y1, int y2){
    int a = y1 - y2;
    int b = x2 - x1;
    int c = - a * x1 - b * y1;
    debug(x1, x2, y1, y2, a, b, c);

    int g = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= g;
    b /= g;
    c /= g;
    if(a < 0 || (a == 0 && b < 0)){
        a *= -1;
        b *= -1;
        c *= -1;
    }


    return tuple<int, int, int>{a, b, c};
}

int inverse_nc2(int x){
    int left = 0, right = 4000;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(mid * (mid - 1) / 2 < x){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

void solve(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    debug(x, y);
    map<tuple<int, int, int>, int> s;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            s[line(x[i], x[j], y[i], y[j])]++;
        }
    }

    ll ans = (ll) n * (ll) (n-1) * (ll) (n-2) / 6;
    debug(ans);
    for(auto it = s.begin(); it != s.end(); it++){
        debug(get<0>(it->first), get<1>(it->first), get<2>(it->first), it->second);
        ll num = inverse_nc2(it->second);
        debug(num);
        ans -= num * (num - 1) * (num - 2) / 6;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}