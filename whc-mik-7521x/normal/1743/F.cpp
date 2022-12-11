#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=998244353;
set<int>s;
struct seg{
    int t01[N<<2],t10[N<<2],t11[N<<2],t00[N<<2];
    void pushup(int rt){
        t01[rt]=(1ll*t00[rt<<1]*t01[rt<<1|1]+1ll*t01[rt<<1]*t11[rt<<1|1])%mod;
        t11[rt]=(1ll*t10[rt<<1]*t01[rt<<1|1]+1ll*t11[rt<<1]*t11[rt<<1|1])%mod;
        t10[rt]=(1ll*t10[rt<<1]*t00[rt<<1|1]+1ll*t11[rt<<1]*t10[rt<<1|1])%mod;
        t00[rt]=(1ll*t00[rt<<1]*t00[rt<<1|1]+1ll*t01[rt<<1]*t10[rt<<1|1])%mod;
    }
    void modify(int rt,int l,int r,int x,int d){
        if(l==r)return (d?(t01[rt]=2,t11[rt]=2,t10[rt]=1,t00[rt]=1):(t01[rt]=0,t11[rt]=2,t10[rt]=1,t00[rt]=3)),void();
        int mid=(l+r)>>1;
        if(x<=mid)modify(rt<<1,l,mid,x,d);
        else modify(rt<<1|1,mid+1,r,x,d);
        pushup(rt);
    }
    int query(int x){return x?t11[1]:t01[1];}
}tr;
int n,ql[N],qr[N],pw2[N],pw3[N],ct[N];
int main(){
	scanf("%d",&n);pw2[0]=pw3[0]=1;int mn=1e9,mx=0;
	for(int i=1;i<=n;i++)scanf("%d%d",&ql[i],&qr[i]);
    for(int i=1;i<=n;i++)pw2[i]=2*pw2[i-1]%mod,pw3[i]=3ll*pw3[i-1]%mod,mn=min(mn,ql[i]),mx=max(mx,qr[i]);
	for(int i=mn;i<=mx;i++)s.insert(i);
	for(int i=n;i;i--){
		auto it=s.lower_bound(ql[i]);
		while(it!=s.end()&&*it<=qr[i])ct[*it]=i,it=s.erase(it);
	}
	int ans=0;
	for(int i=mn;i<=mx;i++)if(ct[i])ans=(ans+1ll*pw2[min(n-1,n-ct[i]+1)]*pw3[max(0,ct[i]-2)])%mod;
	printf("%d",ans);
	return 0;
}