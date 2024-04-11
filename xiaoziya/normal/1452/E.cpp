#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=2005;
int n,m,k;
long long ans;
int l[maxn],r[maxn],id[maxn],sum[maxn];
long long sum2[maxn];
inline int cmp(int a,int b){
	return l[a]+r[a]<l[b]+r[b];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]),id[i]=i;
	sort(id+1,id+1+m,cmp);
	for(int s=0;s<=m;s++){
		long long lmax=0,rmax=0;
		for(int i=1;i<=s;i++)
			sum[l[id[i]]]++,sum[r[id[i]]+1]--;
		for(int i=1;i<=n;i++)
			sum[i]+=sum[i-1],sum2[i]=sum[i]+sum2[i-1],lmax=max(lmax,sum2[i]-sum2[max(i-k,0)]);
		for(int i=0;i<=n;i++)
			sum[i]=sum2[i]=0;
		for(int i=s+1;i<=m;i++)
			sum[l[id[i]]]++,sum[r[id[i]]+1]--;
		for(int i=1;i<=n;i++)
			sum[i]+=sum[i-1],sum2[i]=sum[i]+sum2[i-1],rmax=max(rmax,sum2[i]-sum2[max(i-k,0)]);
		for(int i=0;i<=n;i++)
			sum[i]=sum2[i]=0;
		ans=max(ans,lmax+rmax);
	}
	printf("%lld\n",ans);
	return 0;
}