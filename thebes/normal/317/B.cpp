#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 105

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int N,Q,cnt[2*MAXN][2*MAXN],moves[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
bool in[2*MAXN][2*MAXN];

int main(){
    fastio; cin >> N >> Q;
    cnt[MAXN][MAXN] = N;
    queue<pii> q;
    q.push(mp(MAXN,MAXN));
//    int md = 0;
    while(q.size()){
        int x = q.front().first, y = q.front().second; q.pop();
        in[x][y] = false;
        if(cnt[x][y] < 4) continue;
        for(int i=0; i<4; i++){
            int nx = x+moves[i][0], ny = y+moves[i][1];
            cnt[nx][ny]+=(cnt[x][y]>>2);
//            md = max({md,abs(nx-MAXN),abs(ny-MAXN)});
            if(cnt[nx][ny] >= 4 && !in[nx][ny]){
                in[nx][ny] = true;
                q.push(mp(nx,ny));
            }
        }
        cnt[x][y]%=4;
    }
//    cout << md << endl;
    while(Q--){
        int a,b; cin >> a >> b;
        if(abs(a) > 64 || abs(b) > 64) cout << 0 << endl;
        else cout << cnt[a+MAXN][b+MAXN] << endl;
    }
}