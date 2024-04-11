#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005

int n,m,a[N];

int f[N];
inline bool dp(int x,int s){
	memset(f,0,sizeof(f));
	if(s>1)
		f[s]=std::max(a[s],x);
	for(int i=s+1;i<=n;i++){
		f[i]=f[i-1];
		if(a[i]<=f[i-1]+1)
			f[i]=std::max(f[i],a[i]+x);
		if(i-2>=s&&f[i-2]+1>=a[i]-x)
			f[i]=std::max(f[i],a[i-1]+x);
		if(f[i-1]+1>=a[i]-x)
			f[i]=std::max(f[i],a[i]);
	}
	return f[n]>=std::min(m+a[s]-x-1,m-1);
}
inline bool chk(int x){
	return dp(x,1)||dp(x,2);
}

int main(){
	scanf("%d%d",&m,&n);
	int o=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1&&(!o||a[i]-a[i-1]>a[o]-a[o-1]))
			o=i;
	}
	if(m-a[n]+a[1]>a[o]-a[o-1])
		o=1;
	for(int i=1;i<=n;i++)
		if(i!=o)
			a[i]=(a[i]-a[o]+m)%m;
	a[o]=0;
	std::sort(a+1,a+n+1);
	int l=0,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)){
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",ans);
}