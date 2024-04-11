#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll arr[100100];
vector<int> lis[100100];
ll sps[100100][20];
ll gps[100100][20];
int dep[100100];

void dfs(int here ,int p) {
    dep[here] = dep[p]+1;
    sps[here][0] = p;
    gps[here][0] = arr[here];
    for (int &there : lis[here]){
        if (there==p) continue;
        dfs(there,here);
    }
}

ll gcd(ll a, ll b) {
    if (!a) return b;
    return gcd(b%a,a);
}

ll calc(int v) {
    ll g = arr[v], ans = 0;
    while(v) {
        int rv = v;
        for (int i=19;i>=0;i--) {
            if ((gps[v][i]==0&&g==0)||(g!=0&&gps[v][i]%g==0)) {
                v = sps[v][i];
            }
        }
        ans += g*(dep[rv]-dep[v])%MOD;
        g = gcd(g,arr[v]);
    }
    return ans%MOD;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for (int i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    dfs(1,0);
    for (int j=1;j<20;j++) {
        for (int i=1;i<=n;i++) {
            sps[i][j] = sps[sps[i][j-1]][j-1];
            gps[i][j] = gcd(gps[i][j-1],gps[sps[i][j-1]][j-1]);
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        ans += calc(i);
    }
    printf("%lld\n",ans%MOD);

	return 0;
}