#ifdef __APPLE__
#include "head.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define eef(i,x)for(int i=head[x],y=e[i].to;y;i=e[i].next,y=e[i].to)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c;}
typedef pair<int,int>PII;
typedef long long LL;
const double pi=acos(-1);
const int N=51;
int n, a[N][N];
void add(int x,int y){ a[x][y]=a[y][x]=1; }
int p[N], sz[N];
double dp[N][N], f[N], g[N], C[N][N];
void dfs(int fa,int x,bool tag){
	bool flag=0;
	sz[x]=1;
	ref(i,1,n)if(a[x][i]&&i!=fa){ 
		flag=1; dfs(x,i,1); 
		sz[x]+=sz[i]; 
	}
	if(!flag){ dp[x][0]=0.5; dp[x][1]=1; return; }
	p[0]=0;
	ref(i,1,n)if(a[x][i]&&i!=fa)p[++p[0]]=i;
	int s1=sz[p[1]];
	ref(i,0,s1)f[i]=dp[p[1]][i];
	ref(i,2,p[0]){
		ref(x1,0,s1)ref(x2,0,sz[p[i]])g[x1+x2]+=f[x1]*dp[p[i]][x2];
		s1+=sz[p[i]]; ref(I,0,s1)f[I]=g[I],g[I]=0;
	}
	ref(i,0,s1)dp[x][i+1]=f[i];
	if(tag){
		ref(i,0,s1)ref(j,0,i){
			dp[x][i-j]+=f[i]*0.5*C[i][j]/(s1-i+j+1)/C[s1-i+j][j];
		}
	}
}
int main(){
	n=read();
	ref(i,2,n)add(read(),read());
	ref(i,0,n)C[i][0]=1.0;
	ref(i,1,n)ref(j,1,i)C[i][j]=C[i-1][j]+C[i-1][j-1];
	ref(i,1,n){
		ref(I,0,n)ref(J,0,n)dp[I][J]=0;
		dfs(0,i,0);
		printf("%.10lf\n",dp[i][1]);
	}
}