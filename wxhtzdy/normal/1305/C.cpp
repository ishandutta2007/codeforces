#include <bits/stdc++.h>
using namespace std;
#define ll long long
void mul(ll&a,ll b,int mod){a=(a*b)%mod;}
const int N=200050;
int n;
ll m,a[N];
int main(){
    scanf("%i %i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(n>m)return 0*printf("0");
    ll ans=1;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)mul(ans,abs(a[i]-a[j]),m);
    printf("%lld",ans);
}