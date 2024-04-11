//CF835E
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
const int N = 444444;
int n,f[N],o,b[N],m;
LL d[N],e[N],ans,ss;
vector<int> v[N],h[N],c,p;
int fnd(int x){
	if(x==f[x])
		return x;
	return f[x]=fnd(f[x]);
}
void dfs1(int u,int fa){
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x==fa||b[x])
			continue;
		d[x]=d[u]+h[u][i];
		dfs1(x,u);
	}
	if(d[o]<d[u])
		o=u;
}
void dfs2(int u,int fa){
	if(u==c[0])
		o=0;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x==fa)
			continue;
		if(o){
			c.push_back(u);
			p.push_back(h[u][i]);
		}
		dfs2(x,u);
		if(o){
			c.pop_back();
			p.pop_back();
		}
	}
}
struct node{
	LL x,s,l,r;
	node(LL X=0,LL S=0,LL L=0,LL R=0){
		x=X,s=S,l=L,r=R;
	}
}T[N<<2];
node operator+(node a,node b){
	return node(max(a.r+b.l,max(a.x,b.x)),a.s+b.s,max(a.l,a.s+b.l),max(a.r+b.s,b.r));
}
void build(int k=1,int l=0,int r=m+m-1){
	if(l==r){
		T[k]=node(e[l]+p[l],p[l],e[l],e[l]+p[l]);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	T[k]=T[k<<1]+T[k<<1|1];
}
node query(int L,int R,int k=1,int l=0,int r=m+m-1){
	if(L<=l&&r<=R)
		return T[k];
	int h=l+r>>1;
	node w;
	if(L<=h)
		w=w+query(L,R,k<<1,l,h);
	if(h<R)
		w=w+query(L,R,k<<1|1,h+1,r);
	return w;
}
int main(){
	int i,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		f[i]=i;
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		if(fnd(x)==fnd(y)){
			c.push_back(x);
			c.push_back(y);
			p.push_back(z);
		}
		else{
			f[fnd(x)]=fnd(y);
			v[x].push_back(y);
			v[y].push_back(x);
			h[x].push_back(z);
			h[y].push_back(z);
		}
	}
	o=1;
	x=c[1];
	c.pop_back();
	dfs2(x,0);
	m=c.size();
	for(i=0;i<m;i=i+1){
		b[c[i]]=1;
		c.push_back(c[i]);
		p.push_back(p[i]);
	}
	for(i=0;i<m;i=i+1){
		b[c[i]]=0;
		o=0;
		dfs1(c[i],0);
		e[i]=d[o];
		e[m+i]=d[o];
		x=o;
		o=0;
		d[x]=0;
		dfs1(x,0);
		ss=max(ss,d[o]);
		b[c[i]]=1;
	}
	ans=1e18;
	build();
	for(i=0;i<m;i=i+1)
		ans=min(ans,(query(i,i+m-2)+node(e[i+m-1],0,e[i+m-1],e[i+m-1])).x);
	cout<<max(ans,ss);
	return 0;
}