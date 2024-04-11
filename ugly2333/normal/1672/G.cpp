//CF1627G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 4096;
const int MO = 998244353;
int n,m,a[N],f[N],sz[N],g[N],p2[N*N];
char c[N][N],d[N][N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void uni(int x,int y){
	if(x!=y){
		sz[x]+=sz[y];
		f[y]=x;
	}
}
int main()
{
	int i,j,k=0,l,x,s,s0,s1;
	p2[0]=1;
	for(i=1;i<N*N;i++)
		p2[i]=p2[i-1]*2%MO;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	if(n%2==1&&m%2==0){
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				d[i][j]=c[i][j];
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				c[j][i]=d[i][j];
		swap(n,m);
	}
	for(i=1;i<=n+m;i++)
		f[i]=i,sz[i]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]!='?'){
				a[i]^=c[i][j]-'0';
				a[n+j]^=c[i][j]-'0';
			}
			else{
				k++;
				uni(fnd(i),fnd(n+j));
			}
		}
	}
	if(n%2==0&&m%2==0){
		printf("%d\n",p2[k]);
		return 0;
	}
	if(n%2==1&&m%2==1){
		s=0;
		memset(g,0,sizeof(g));
		for(i=1;i<=n+m;i++)
			g[fnd(i)]^=a[i];
		x=1;
		l=0;
		for(i=1;i<=n+m;i++)
			if(f[i]==i){
				if(g[i])
					x=0;
				l+=sz[i]-1;
			}
		s+=x*p2[k-l];
		for(i=1;i<=n+m;i++)
			a[i]^=1;
		memset(g,0,sizeof(g));
		for(i=1;i<=n+m;i++)
			g[fnd(i)]^=a[i];
		x=1;
		l=0;
		for(i=1;i<=n+m;i++)
			if(f[i]==i){
				if(g[i])
					x=0;
				l+=sz[i]-1;
			}
		s+=x*p2[k-l];
		printf("%d\n",s%MO);
		return 0;
	}
	s0=1,s1=1;
	x=0;
	for(i=1;i<=n;i++){
		l=0;
		for(j=1;j<=m;j++)
			l+=c[i][j]=='?';
		if(l==0){
			if(a[i])
				s0=0;
			else
				s1=0;
		}
		else
			x++;
	}
	printf("%d\n",(LL)(s0+s1)*p2[k-x]%MO);
	return 0;
}