#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
constexpr int max_n=64;
constexpr int max_m=256;
int a[max_n+1][max_n+1];
int f[max_m+1][max_m+1];
bool done[max_m+1];
int g[max_m+1];
bool insert(const int m){
	for(int i=1; i<=m; ++i)
		if(g[i]){
			if(f[i][i]){
				int*h=f[i];
				if(g[i]==h[i]){
					g[i]=0;
					if(!done[i])
						for(int j=i; ++j<=m; (g[j]-=h[j])<0&&(g[j]+=3));
					(g[0]-=h[0])<0&&(g[0]+=3);
				}
				else{
					g[i]=0;
					if(!done[i])
						for(int j=i; ++j<=m; (g[j]+=h[j])>2&&(g[j]-=3));
					(g[0]+=h[0])>2&&(g[0]-=3);
				}
			}
			else{
				f[i][0]=g[0];
				bool flg=1;
				for(int j=i; ++j<=m; )
					if(g[j]){
						flg=0;
						break;
					}
				if(flg)
					done[i]=1,f[i][i]=g[i];
				else
					memcpy(f[i]+i,g+i,(m-i+1)<<2);
				return 1;
			}
		}
	if(g[0])
		return 0;
	return 1;
}
void flush(const int i,const int m){
	int*h=f[i];
	if(!done[i])
		for(int j=i; ++j<=m; )
			if(h[j]){
				if(h[j]==1)
					(h[0]-=f[j][0])<0&&(h[0]+=3);
				else
					(h[0]+=f[j][0])>2&&(h[0]-=3);
				h[j]=0;
			}
	if(h[i]==2){
		h[i]=1;
		if(h[0])
			h[0]^=3;
	}
	done[i]=1;
}
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j]=0;
	for(int i=1; i<=m; ++i){
		memset(f[i],0,(m+1)<<2);
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		a[u][v]=a[v][u]=i;
		if(c>0)
			f[i][i]=1,f[i][0]=c%3,done[i]=1;
		else
			done[i]=0;
	}
	int mn=m;
	for(int i=1; i<=n; ++i)
		for(int j=i,x; ++j<=n; )
			if((x=a[i][j]))
				for(int k=j,y,z; ++k<=n; )
					if((y=a[j][k])&&(z=a[i][k])){
						memset(g,0,(m+1)<<2);
						g[x]=g[y]=g[z]=1;
						if(!insert(m)){
							puts("-1");
							return;
						}
						while(mn&&f[mn][mn]){
							if(!done[mn])
								flush(mn,m);
							--mn;
						}
					}
	for(int i=m; i; --i)
		if(f[i][i])
			flush(i,m);
		else
			f[i][i]=1,f[i][0]=0;
	for(int i=1; i<=m; ++i)
		printf("%d ",f[i][0]?f[i][0]:3);
	puts("");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}