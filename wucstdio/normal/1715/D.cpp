#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 100010
#define M 3000030
#define ll long long
using namespace std;
ll n,Q,u[N*2],v[N*2],w[N*2],a[N][35],ans;
int hea[N][35],cnt,qu,x,f;
struct de{
	int to,net,wei;
}lu[M*4];
void add(int fr,int to,int wei){
	lu[++cnt].to=to;
	lu[cnt].net=hea[fr][wei];
	hea[fr][wei]=cnt;
	lu[cnt].wei=wei;
}
int main()
{
	scanf("%lld%lld",&n,&Q);
	memset(a,-1,sizeof(a));
	for(int i=1;i<=Q;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
		if(u[i]==v[i]){
			for(int j=0;j<=30;j++)
				a[u[i]][j]=(w[i]>>j)&1;
			continue;
		}
		for(int j=0;j<=30;j++){
			if((1<<j)&w[i]){
				add(u[i],v[i],j);
				add(v[i],u[i],j);
			}
			else a[u[i]][j]=a[v[i]][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i][j]==-1){
				f=0;
				for(int x=hea[i][j];x;x=lu[x].net){
					qu=lu[x].to;
					if(a[qu][j]==0)
						f=1;
				}
				if(f) a[i][j]=1;
				else a[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=0;j<=30;j++){
			if(a[i][j]==1) ans+=(1<<j);
		}
		printf("%lld ",ans);
	}
	return 0;
}