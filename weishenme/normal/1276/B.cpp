#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005; 
int T,n,m,a,b,x[N],flag1[N],flag2[N],y[N],f[N],cnt[N];
int find(int x){
	if (x==f[x])return x;
	return f[x]=find(f[x]);
}
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
		for (int i=1;i<=n;i++)flag1[i]=flag2[i]=0;
		for (int i=1;i<=m;i++)scanf("%lld%lld",&x[i],&y[i]);
		int ans=0;
		for (int i=1;i<=n;i++)f[i]=i,cnt[i]=0;	
		for (int i=1;i<=m;i++)
			if (x[i]!=a&&y[i]!=a&&x[i]!=b&&y[i]!=b)f[find(x[i])]=find(y[i]);
		for (int i=1;i<=n;i++)
			if (i!=a&&i!=b)cnt[find(i)]++;
		for (int i=1;i<=n;i++)
			if (find(i)==i)ans-=cnt[i]*(cnt[i]-1)/2;
		ans+=(n-2)*(n-3)/2;	
		int sum=0;
		for (int i=1;i<=m;i++){
			if (x[i]==a){
				if (y[i]!=b&&!flag1[find(y[i])])
					flag1[find(y[i])]=1,ans-=sum*cnt[find(y[i])],sum+=cnt[find(y[i])];
			}
			else if (y[i]==a){
				if (x[i]!=b&&!flag1[find(x[i])])
					flag1[find(x[i])]=1,ans-=sum*cnt[find(x[i])],sum+=cnt[find(x[i])];
			}
		} 
		sum=0;
		for (int i=1;i<=m;i++){
			if (x[i]==b){
				if (y[i]!=a&&!flag2[find(y[i])])
					flag2[find(y[i])]=1,ans-=sum*cnt[find(y[i])],sum+=cnt[find(y[i])];
			}
			else if (y[i]==b){
				if (x[i]!=a&&!flag2[find(x[i])])
					flag2[find(x[i])]=1,ans-=sum*cnt[find(x[i])],sum+=cnt[find(x[i])];
			}
		}
		sum=0;
		for (int i=1;i<=n;i++)
			if (flag1[i]&&flag2[i])ans+=sum*cnt[i],sum+=cnt[i];		
		printf("%lld\n",ans);						
	}
}