//CF1450E
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
const int N = 2222;
const int inf = 1e9;
int n,m,c[N],fl,w,a[N],b[N];
vector<int> v[N],g[N],h[N];
void dfs(int u,int cc){
	if(c[u]>=0){
		if(c[u]!=cc)
			fl=0;
		return;
	}
	c[u]=cc;
	int i,x;
	for(i=0;i<v[u].size();i=i+1)
		dfs(v[u][i],c[u]^1);
}
void ade(int x,int y,int z){//cout<<x<<y<<z<<endl;
	g[x].push_back(y);
	h[x].push_back(z);
}
int d[N],he,ta,q[N*N],inq[N],cnt[N];
int spfa(int s){
	int i,x,y;
	for(i=1;i<=n;i=i+1)
		d[i]=inf,inq[i]=0,cnt[i]=0;
	he=0,ta=0;
	d[s]=0;
	q[ta++]=s,inq[s]=1,cnt[s]++;
	while(he<ta){
		x=q[he++];
		inq[x]=0;
		for(i=0;i<g[x].size();i=i+1){
			y=g[x][i];
			if(d[y]>d[x]+h[x][i]){
				d[y]=d[x]+h[x][i];
				if(!inq[y])
					q[ta++]=y,inq[y]=1,cnt[y]++;
				if(cnt[y]>=222)
					return -inf;
			}
		}
	}
	x=0;
	for(i=1;i<=n;i=i+1)
		x=max(x,d[i]*2+c[i]-c[s]);
	return x;
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y);
		v[y].push_back(x);
		if(z){
			w++;
			a[w]=x;
			b[w]=y;
		}
	}
	fl=1;
	for(i=1;i<=n;i=i+1)
		c[i]=-1;
	dfs(1,1);
	if(!fl){
		printf("NO");
		return 0;
	}
	for(i=1;i<=n;i=i+1){
		for(j=0;j<v[i].size();j=j+1){
			x=v[i][j];
			ade(x,i,(1-c[i]+c[x])/2);
		}
	}
	for(i=1;i<=w;i=i+1)
		ade(b[i],a[i],(-1-c[a[i]]+c[b[i]])/2);
	x=spfa(1);
	if(x<=-inf){
		printf("NO");
		return 0;
	}
	j=1;
	for(i=2;i<=n;i=i+1){
		y=spfa(i);
		if(x<y)
			x=y,j=i;
	}
	spfa(j);
	printf("YES\n%d\n",x);
	for(i=1;i<=n;i=i+1)
		printf("%d ",d[i]*2+c[i]+1000);
	return 0;
}