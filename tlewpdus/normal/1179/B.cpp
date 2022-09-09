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

int n, m;

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=1;i<n+1-i;i++) {
        for (j=1;j<=m;j++) {
            printf("%d %d\n%d %d\n",i,j,n+1-i,m+1-j);
        }
    }
    if (n%2==1) {
        for (j=1;j<m+1-j;j++) {
            printf("%d %d\n%d %d\n",(n+1)/2,j,(n+1)/2,m+1-j);
        }
        if (m%2==1) {
            printf("%d %d\n",(n+1)/2,(m+1)/2);
        }
    }

    return 0;
}