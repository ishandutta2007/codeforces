//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;
const int SQRT = 400;

vector<int> subset[N];
vector<int> big;
ll added[N], ba[N];
ll initial[N];
int big_id[N];
bool is[N][N/SQRT + 3];
int32_t common[N][N/SQRT + 3];
int n, m, q;
ll a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d%d", &n, &m, &q);
    F(i, 0, n)
        scanf("%lld", a + i);
    F(i, 0, m){
        big_id[i] = -1;
        int sz;
        scanf("%d", &sz);
        subset[i].resize(sz);
        F(j, 0, sz){
            scanf("%d", &subset[i][j]);
            --subset[i][j];
            initial[i] += a[subset[i][j]];
        }
        if(sz >= SQRT){
            big.pb(i);
            big_id[i] = (int)big.size() - 1;
            I(x, subset[i])is[x][big_id[i]] = 1;
        }
    }
    F(i, 0, m){
        I(x, subset[i]){
            F(j, 0, (int)big.size())
                if(is[x][j])++common[i][j];
        }
    }
    F(i, 0, q){
        char c;
        int v, x;
        scanf(" %c%d", &c, &v);
        if(c == '+')
            scanf("%d", &x);
        --v;
        if(c == '+'){
            if(big_id[v] == -1){
                I(j, subset[v]){
                    a[j] += x;
                }
                I(j, big){
                    added[j] += x * 1ll * common[v][big_id[j]];
                }
            }
            else{
                ba[v] += x;
            }
        }
        else{
            ll ans = 0;
            if(big_id[v] == -1){
                I(j, subset[v])ans += a[j];
                I(j, big)ans += ba[j] * common[v][big_id[j]];
            }
            else{
                ans = added[v] + initial[v];
                I(j, big)ans += ba[j] * common[v][big_id[j]];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}