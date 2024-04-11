#include<cstdio>
#include<algorithm>
#define P 1000000007
#define N 400005

int T;

int n,p[N],q[N];

bool vis[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&q[p[i]]);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int ans=1;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				ans=(ans<<1)%P;
				vis[i]=1;
				for(int j=q[i];j!=i;j=q[j])
					vis[j]=1;
			}
		printf("%d\n",ans);
	}
}