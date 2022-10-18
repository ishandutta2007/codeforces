#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define eb emplace_back
#define ef emplace_front
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define F first
#define S second
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) { \
    for(auto pv : a) b << pv << " "; \
    b << "\n"; \
}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a/ b;
}

const int sz = 1000;
vector<vector<int>> g;
vector<int> dis;
int mxc = 0;

void build(){

    g.resize(sz + 1);

    for(int i = 1; i <= sz; i++){
        for(int j = i; j > 0; ){
            int t = i / j;
            if(i + t <= sz) g[i].eb(i + t);
            j = i / (t + 1);
        }
    }

    queue<int> q;
    q.push(1);
    dis.resize(sz + 1, -1);
    dis[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i : g[now]){
            if(dis[i] != -1) continue;
            dis[i] = dis[now] + 1;
            q.push(i);
        }
    }
    
    mxc = max(mxc, *max_element(iter(dis)));

}

void solve(){
    
    int n, k;
    cin >> n >> k;
    k = min(n * mxc, k);

    vector<int> b(n + 1), c(n + 1);
    for(int i =1 ; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    vector<int> dp(k + 1);
    for(int i = 1; i <= n; i++){
        int w = dis[b[i]], v = c[i];

        for(int j = k; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    
    cout << *max_element(iter(dp)) << "\n";

}

int main(){
    StarBurstStream;

    build();


    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}