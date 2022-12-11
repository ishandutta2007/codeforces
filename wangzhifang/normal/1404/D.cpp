#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
constexpr int max_n=500000;
pair<int,int>a[max_n+1];
int g[max_n<<1|1];
bool vis[max_n<<1|1],used[max_n<<1|1];
int main(){
	int n;
	scanf("%d",&n);
	if(!(n&1)){
		puts("First");
		for(int i=1; i<=n; ++i)
			printf("%d ",i);
		for(int i=1; i<n; ++i)
			printf("%d ",i);
		printf("%d\n",n);
		return 0;
	}
	puts("Second");
	fflush(stdout);
	for(int i=1,ed=n<<1,x; i<=ed; ++i){
		scanf("%d",&x);
		(a[x].first?a[x].second:a[x].first)=i;
	}
	for(int i=1; i<=n; ++i)
		g[a[i].first]=a[i].second,g[a[i].second]=a[i].first;
	long long sum=0;
	memset(vis+1,0,n),memset(used+1,0,n);
	for(int i=1; i<=n; ++i)
		if(!vis[i]){
			vis[i]=1,used[i]=1,sum+=i;
			vis[g[i]]=1;
			for(int j=g[i]<=n?g[i]+n:(g[i]-n); j!=i; j=g[j]<=n?g[j]+n:(g[j]-n)){
				vis[j]=1,used[j]=1,sum+=j;
				vis[g[j]]=1;
			}
		}
	if((sum%(n<<1))){
		memset(vis+1,0,n);
		for(int i=1; i<=n; ++i)
			if(!vis[i]){
				vis[i]=1;
				vis[g[i]]=1;
				int cnt=1;
				for(int j=g[i]<=n?g[i]+n:(g[i]-n); j!=i; j=g[j]<=n?g[j]+n:(g[j]-n)){
					vis[j]=1,cnt^=1;
					vis[g[j]]=1;
				}
				if((cnt&1)){
					used[i]=0,used[g[i]]=1;
					for(int j=g[i]<=n?g[i]+n:(g[i]-n); j!=i; j=g[j]<=n?g[j]+n:(g[j]-n))
						used[j]=0,used[g[j]]=1;
					break;
				}
			}
	}
	for(int i=1,ed=n<<1; i<=ed; ++i)
		if(used[i])
			printf("%d ",i);
	return 0;
}