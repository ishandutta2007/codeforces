#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+9;
const int V = 5e6+9;
int n,cnt;ll sum[N],a[N];
struct pp{int l,r;}ans[V];
bool cmp(pp x,pp y){return x.l==y.l?(x.r<y.r):(x.l<y.l);}
int main(){
    scanf("%d",&n);cnt=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<n;i++){
        ll k=(ll)log2(a[i])+1;
        for(int j=i+2;j<=n;j++){
            if(sum[j-1]-sum[i]>=(1ll<<k)) break;
            if((a[i]^a[j])==(sum[j-1]-sum[i])){
                ans[++cnt].l=i,ans[cnt].r=j;
            }
        }
    }
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<n;i++){
        ll k=(ll)log2(a[i])+1;
        for(int j=i+2;j<=n;j++){
            if(sum[j-1]-sum[i]>=(1ll<<k)) break;
            if((a[i]^a[j])==(sum[j-1]-sum[i])){
                ans[++cnt].l=n-j+1,ans[cnt].r=n-i+1;
            }
        }
    }
    int Ans=0;
    sort(ans+1,ans+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
        if(ans[i].l!=ans[i-1].l||ans[i].r!=ans[i-1].r) Ans++;
    printf("%d\n",Ans);
    return 0;
}