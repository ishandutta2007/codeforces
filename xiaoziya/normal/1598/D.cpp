#include<stdio.h>
#include<map>
using namespace std;
const int maxn=200005;
int T,n;
int a[maxn],b[maxn],reca[maxn],recb[maxn];
long long ansa,ansb,ans;
map<int,int>mpa,mpb;
int main(){
	scanf("%d",&T);
	while(T--){
		ansa=ansb=0,mpa.clear(),mpb.clear(),scanf("%d",&n),ans=1ll*n*(n-1)*(n-2)/6;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]),mpa[a[i]]++,mpb[b[i]]++;
		for(int i=1;i<=n;i++) 
			ans-=1ll*(mpa[a[i]]-1)*(mpb[b[i]]-1);
		//topic same/difficulties same
		printf("%lld\n",ans);
	}
	return 0;
}