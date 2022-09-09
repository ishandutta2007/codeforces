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

int n, m, a, b;

int par[200100];
void init(int n) {
    for (int i=0;i<n;i++) par[i] = i;
}
int fin(int a) {
    return par[a]=(par[a]==a?a:fin(par[a]));
}
void uni(int a, int b) {
    par[fin(a)] = fin(b);
}

int col[200100];

int main() {
    int t;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d",&n,&m,&a,&b); --a; --b;
        for (int i=0;i<n;i++) col[i] = 0;
        init(n);
        for (int i=0;i<m;i++) {
            int u, v;
            scanf("%d%d",&u,&v); --u; --v;
            if (u!=a&&u!=b&&v!=a&&v!=b) {
                uni(u,v);
            }
            else {
                if (u==a) col[v] |= 1;
                if (v==a) col[u] |= 1;
                if (u==b) col[v] |= 2;
                if (v==b) col[u] |= 2;
            }
        }
        for (int i=0;i<n;i++) {
            col[fin(i)] |= col[i];
        }
        int ac = 0, bc = 0;
        for (int i=0;i<n;i++) {
            if (i==a||i==b) continue;
            if (col[fin(i)]==1) {
                ac++;
            }
            else if (col[fin(i)]==2) {
                bc++;
            }
        }
        printf("%lld\n",1LL*ac*bc);
    }

	return 0;
}