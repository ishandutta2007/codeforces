#include<cstdio>
#include<algorithm>
#define ll long long
#define N 300005

int T;

int n,m;

int a[N],b[N];

ll ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		std::sort(a+1,a+n+1);
		std::reverse(a+1,a+n+1);
		ans=0;
		for(int i=1,j=1;i<=n;i++){
			if(j<a[i])
				ans+=b[j++];
			else
				ans+=b[a[i]];
		}
		printf("%lld\n",ans);
	}
}