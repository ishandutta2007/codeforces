#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long t,n,nn,a[N],s[N],b[N],f[N],dp[N];
struct BIT{
	long long ts[N];
    void init(int x){
        for(int i=0;i<=x;i++)ts[i]=-1e18;
    }
	void add(int x,long long y){
        for(;x<N;x+=x&-x)ts[x]=max(ts[x],y);
    }
	long long ask(int x){
		long long res=-9e18;
		for(;x;x-=x&-x)res=max(res,ts[x]);
		return res;
	}
}tr;
int main(){
    scanf("%lld",&t);
	while(t--){
        scanf("%lld",&n);
        tr.init(n+10);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i],b[i]=s[i];
		b[n+1]=0;
		sort(b+1,b+n+2);
        nn=unique(b+1,b+n+2)-b-1;
		for(int i=1;i<=nn;i++)f[i]=-1e18;
		int x=lower_bound(b+1,b+nn+1,0)-b;
		tr.add(x,0);
        f[x]=0;
		for(int i=1;i<=n;i++){
			x=lower_bound(b+1,b+nn+1,s[i])-b;
			dp[i]=max(dp[i-1],max(2*i+tr.ask(x-1),i+f[x]));
			tr.add(x,dp[i]-2*i);
            f[x]=max(f[x],dp[i]-i);
		}
        printf("%lld\n",dp[n]-n);
	}
	return 0;
}