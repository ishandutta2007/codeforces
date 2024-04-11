#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, q;
int S[4100];
int sum[4100];
int W[20];
char str[20];
int que[500100];
int quek[500100];
int ans[4100][110];

int main() {
    int i, j;

    scanf("%d%d%d",&n,&m,&q);
    for (i=0;i<n;i++) {
        scanf("%d",&W[i]);
    }
    for (i=0;i<m;i++) {
        scanf("%s",str);
        int v = 0;
        for (j=0;j<n;j++) {
            v = v*2+(str[j]-'0');
        }
        S[v]++;
    }
    for (i=0;i<(1<<n);i++) {
        int v = 0;
        for (j=0;j<n;j++) {
            if ((i>>j&1)==0) v += W[n-1-j];
        }
        sum[i] = v;
    }
    for (i=0;i<q;i++) {
        scanf(" %s%d",str,&quek[i]);
        int v = 0;
        for (j=0;j<n;j++) {
            v = v*2+(str[j]-'0');
        }
        que[i] = v;
    }
    for (i=0;i<(1<<n);i++) {
        for (j=0;j<(1<<n);j++) {
            ans[i][min(sum[i^j],101)]+=S[j];
        }
        for (j=1;j<101;j++) ans[i][j] += ans[i][j-1];
    }
    for (i=0;i<q;i++) {
        printf("%d\n",ans[que[i]][quek[i]]);
    }

    return 0;
}