#include<cstdio>
#include<algorithm>
#define ll long long
#define N 5005

int T;

int n,a[N];

int f[N];
inline int fnd(int x){
	return x>n?n+1:(f[x]?f[x]=fnd(f[x]):x);
}

int main(){
//	freopen(".in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n+1;i++)
			f[i]=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				f[fnd(i)]=fnd(i+1);
		ll ans=0;
		while(1){
			int o=fnd(1);
			if(o>n)
				break;
			if(a[o]>n-o+1){
				ans+=a[o]-(n-o+1);
				a[o]=n-o+1;
				if(a[o]==1)
					f[fnd(o)]=fnd(o+1);
				continue;
			}
			ans++;
//			printf("&%d %d\n",o,a[o]);
			while(o<=n){
				int tmp=o;
				o=fnd(o+a[o]);
				a[tmp]=std::max(a[tmp]-1,1);
//				printf("^%d %d\n",tmp,a[tmp]);
//				system("pause");
				if(a[tmp]==1)
					f[fnd(tmp)]=fnd(tmp+1);
			}
//			for(int i=1;i<=n;i++)
//				printf("%d ",a[i]);
//			puts("");
//			for(int i=1;i<=n;i++)
//				printf("%d ",f[i]);
//			puts("");
		}
		printf("%lld\n",ans);
	}
}