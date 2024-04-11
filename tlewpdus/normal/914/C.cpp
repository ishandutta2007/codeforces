#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

int pcnt[1100];
int n, k;
char arr[1100];
int ps[1100];
ll MOD = 1000000007;

ll tab[1100][1100];
int di[1100];

void dp() {
    int i, j;
    if (arr[0]) {
        tab[0][0] = tab[0][1] = 1;
    }
    else tab[0][0] = 1;
    for (i=1;i<n;i++) {
        for (j=0;j<=1010;j++) {
            if (j) {
                tab[i][j] += tab[i-1][j-1]-(arr[i]==0&&j-1==ps[i-1])+MOD;
            }
            tab[i][j] += tab[i-1][j];
            tab[i][j] %=MOD;
        }
    }
}

int main() {
    int i;

    pcnt[0] = 0; di[1] = 0;
    for (i=1;i<=1010;i++) {
        pcnt[i] = pcnt[i-(i&-i)]+1;
        if (i!=1) di[i] = di[pcnt[i]]+1;
    }
    scanf(" %s",arr); n = strlen(arr);
    for (i=0;i<n;i++) arr[i]-='0';
    for (i=0;i<n;i++) ps[i] = (i?ps[i-1]:0)+arr[i];
    scanf(" %d",&k);
    if (k==0) {
        printf("1\n");
        return 0;
    }
    dp();
    ll res = 0;
        for (i=1;i<=n;i++) {
            if (di[i]==k-1) {
                res = (res+tab[n-1][i])%MOD;
            }
        }
    if (k==1) res = (res + MOD-1)%MOD;
    printf("%lld\n",res);

    return 0;
}