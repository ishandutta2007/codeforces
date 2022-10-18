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

int INF = 1e9 + 7;

int n;

int ask(int x){
    if(x == 0 || x == n+1) return INF;
    cout << "? " << x << endl;
    int a;
    cin >> a;
    return a;
}

void solve(){
    cin >> n;
    int left = 0, right = n + 1;
    int mid = left + (right - left) / 2;
    int lv = INF, rv = INF;
    int mv = ask(mid);

    while(left + 1 < mid || mid + 1 < right){
        int nl = left + (mid - left) / 2;
        int nr = mid + (right - mid + 1) / 2;
        debug(left, right, mid, nl, nr);
        int nlv = ask(nl), nrv = ask(nr);
        if(nlv < mv){
            right = mid;
            rv = mv;
            mid = nl;
            mv = nlv;
        }
        else if(nrv < mv){
            left = mid;
            lv = mv;
            mid = nr;
            mv = nrv;
        }
        else{
            left = nl;
            lv = nlv;
            right = nr;
            rv = nrv;
        }
    }

    cout << "! " << mid << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}