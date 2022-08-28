//CF1427G
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
const int N = 222;
const int M = N*N;
const int inf = 1e9;
struct edge{
	int pr;
	int to;
	int cap;
}e[222222];
int tot=1,la[M];
void clr(){
	tot=1;
	memset(la,0,sizeof(la));
}
void adde(int x,int y,int z){
	e[++tot].pr=la[x];
	la[x]=tot;
	e[tot].to=y;
	e[tot].cap=z;
}
void addf(int x,int y,int z=4,int z2=0){//cout<<x<<' '<<y<<' '<<z<<' '<<z2<<endl;
	adde(x,y,z);
	adde(y,x,z2);
}
int d[M],g[M],q[M],he,ta;
int bfs(int s,int t){
	int i,x,y;
	memset(d,0,sizeof(d));
	d[s]=1;
	he=0,ta=0;
	q[ta++]=s;
	while(he<ta){
		x=q[he++];
		if(x==t)
		    break;
		for(i=la[x];i;i=e[i].pr){
			if(!e[i].cap)
				continue;
			y=e[i].to;
			if(!d[y]){
				d[y]=d[x]+1;
				g[y]=i;
				q[ta++]=y;
			}
		}
	}
	if(!d[t])
	    return 0;
	for(x=t;x!=s;x=e[i^1].to){
	    i=g[x];
	    e[i^1].cap++;
	    e[i].cap--;
	}
	return 1;
}
int maxflow(int s,int t,int f=4){
	int x,r=0;
	while(f){
		x=bfs(s,t);
	    if(!x)
	        return r;
	    r+=x;
	    f-=x;
	}
	return r;
}
int n,a[N][N],m,b[N][N],l,c[M],h[M],s,t,f;
pair<int,int> p[M];
LL ans;
int main()
{
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1){
			scanf("%d",a[i]+j);
			if(a[i][j]!=-1)
				b[i][j]=++m;
			if(a[i][j]>0)
				p[++l]=make_pair(a[i][j],m);
		}
	}
	sort(p+1,p+l+1);
	s=m+1,t=m+2;
	for(i=1;i<=l;i=i+1){
		x=p[i].second;
		addf(x,t);
		h[x]=tot;
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<n;j=j+1)
			if(b[i][j]&&b[i][j+1])
				addf(b[i][j],b[i][j+1],1,1);
	for(i=1;i<n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(b[i][j]&&b[i+1][j])
				addf(b[i][j],b[i+1][j],1,1);
	f=0;
	ans=0;
	for(i=1;i<=l;i=i+1){
		ans+=(LL)f*(p[i].first-p[i-1].first);
		x=p[i].second;
		j=e[h[x]].cap;
		e[h[x]].cap=0;
		e[h[x]^1].cap=0;
		f-=maxflow(x,s,j);
		addf(s,x);
		f+=maxflow(s,t);
	}
	cout<<ans;
	return 0;
}