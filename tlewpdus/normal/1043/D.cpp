#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n, m;
int perm[10][100100];
int loc[10][100100];
int key[10];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            scanf("%d",&perm[i][j]); perm[i][j]--;
            loc[i][perm[i][j]] = j;
        }
    }
    int p = 0;
    memset(key,-1,sizeof(key));
    ll ans = 0;
    for (j=0;j<n;j++) {
        int v = perm[0][j];
        int fl = 1;
        for (i=0;i<m;i++) {
            if (key[i]>=0&&key[i]+1!=loc[i][v]) fl = 0;
            key[i] = loc[i][v];
        }
        if (!fl) {
            ans += 1LL*(j-p)*(j-p+1)/2;
            p = j;
            memset(key,-1,sizeof(key));
            j--;
        }
    }
    ans += 1LL*(j-p)*(j-p+1)/2;
    printf("%lld\n",ans);

    return 0;
}