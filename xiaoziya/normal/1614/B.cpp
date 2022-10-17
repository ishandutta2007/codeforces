#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=200005;
int T,n;
int a[maxn],id[maxn],res[maxn];
long long ans;
inline int cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),id[i]=i;
		sort(id+1,id+1+n,cmp);
		res[0]=n;
		for(int i=1;i<=n;i++)
			ans+=2ll*((i+1)/2)*a[id[i]],res[id[i]]=(i&1)? (n-(i+1)/2):(n+(i+1)/2);
		printf("%lld\n",ans);
		for(int i=0;i<=n;i++)
			printf("%d%c",res[i],i==n? '\n':' ');
	}
	return 0;
}