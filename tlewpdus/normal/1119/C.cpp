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
int arr[510][510], brr[510][510];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&arr[i][j]);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&brr[i][j]);
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) arr[i][j]^=brr[i][j];
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) arr[i][j]^=((arr[i-1][j]^arr[i][j-1])^arr[i-1][j-1]);
    int c = 1;
    for (i=1;i<=n;i++) if (arr[i][m]) c = 0;
    for (i=1;i<=m;i++) if (arr[n][i]) c = 0;
    if (c) printf("Yes\n");
    else printf("No\n");

    return 0;
}