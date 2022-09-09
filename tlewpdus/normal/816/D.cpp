#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

ll MOD = 1000000007;
ll pas[200100];
ll bae[200100];
ll arr[200100];

ll power(ll a, ll n) {
    if (n==0) return 1;
    ll t = power(a,n/2);
    if (n%2) return ((((t*t)%MOD)*a)%MOD);
    return (((t*t)%MOD));
}
//int pas[3010][3010];
/*
int pa(int i, int j) {
    if (i<0||j<0) return 0;
    return pas[i][j];
}
*/
int main() {
    int i, j, m;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%I64d",&arr[i]);
    n--;
    m = n/2;
    if (n%4==2) m--;
    pas[0] = 1;
    for (i=1;i<=m;i++) {
        pas[i] = (((pas[i-1]*(m-i+1))%MOD)*power(i,MOD-2))%MOD;
        //printf("%lld ",pas[i]);
    }
/*
    for (i=0;i<=n;i++) {
        for (j=0;i+j<=n;j++) {
            pas[i][j] = ((((n*(n+1)/2+1)%2)+((i+j-1)*(i+j)/2+i)%2)%2)?(pa(i-1,j)-pa(i,j-1)):(pa(i-1,j)+pa(i,j-1));
            if (i==0&&j==0) pas[i][j] = 1;
        }
    }
    for (i=n;i>=0;i--) {
        printf("%d ",pas[i][n-i]);
    }
*/

    if (n%4==0) {
        for (i=0;i<=n;i++) {
            if (i%2==1) bae[i] = 0;
            else bae[i] = pas[i/2];
        }
    }
    else if (n%4==1) {
        for (i=0;i<=n;i++) {
            bae[i] = pas[i/2];
        }
    }
    else if (n%4==2) {
        for (i=0;i<=n;i++) {
            if (i<=n/2) {
                if (i&1) bae[i] = (pas[i/2]*2)%MOD;
                else bae[i] = (((pas[i/2]*(m-i/2-i/2+1))%MOD)*power(m-i/2+1,MOD-2))%MOD;
            }
            else bae[i] = bae[n-i];
            if (i>=n/2&&((i-n/2)%2==1)) bae[i] = -bae[i];
        }
    }
    else {
        int s = 1;
        for (i=0;i<=n;i++) {
            bae[i] = pas[i/2]*s;
            s = -s;
        }
    }
    //for (i=0;i<=n;i++) printf("%lld ",bae[i]);
    ll res = 0;
    for (i=0;i<=n;i++) {
        //printf("%lld ",bae[i]);
        res += (arr[i]*bae[i])%MOD;
        res %= MOD;
    }
    printf("%I64d\n",((res+MOD)%MOD));


    return 0;
}