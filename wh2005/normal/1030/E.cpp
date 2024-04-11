#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+9;
int n,c[N],sum[N];ll a[N],cnt[2];
ll lowbit(ll x){return x&(-x);}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        while(a[i]){a[i]-=lowbit(a[i]),c[i]++;}
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+c[i];
    ll ans=0;cnt[0]=1,cnt[1]=0;
    for(int r=1;r<=n;r++){
        int l=max(r-128,1),mx=c[r];
        ans+=cnt[sum[r]%2];
        for(int i=r;i>=l;i--){
            mx=max(c[i],mx);
            if((sum[r]-sum[i-1])%2==0&&mx>(sum[r]-sum[i-1]-mx)) ans--;
        }
        cnt[sum[r]%2]++;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
Vasyan64R

7(...000111)11(...001011)22(...010110),
Vasya0
00
na_1,a_2,a_3...a_n
(l,r),1<=l<=r<=n,a_l,a_l+1,...,a_r
*/