#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=200005;
int T,n;
int a[maxn];
long long sum;
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),sum=0,mp.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		if((2*sum)%n){
			puts("0");
			continue;
		}
		long long v=2*sum/n,ans=0;
		for(int i=1;i<=n;i++)
			ans+=mp[v-a[i]],mp[a[i]]++;
		printf("%lld\n",ans);
	}
	return 0;
}