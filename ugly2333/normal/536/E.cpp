//CF536E
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
const int N = 111111;
int n,q,f[N];
struct node{
	bool e;
	int l,r,s;
	node(int x=0){
		e=x,l=x,r=x,s=0;
	}
	int ans(){
		//cout<<e<<l<<r<<s<<endl;
		if(e)
			return f[l];
		return s+f[l]+f[r];
	}
}t[1<<19],em;
node rev(node a){
	swap(a.l,a.r);
	return a;
}
node operator+(node a,node b){
	node c;
	c.e=a.e&b.e;
	c.l=a.l+a.e*b.l;
	c.r=b.r+b.e*a.r;
	c.s=a.s+b.s;
	if(!a.e&&!b.e)
		c.s+=f[a.r+b.l];
	return c;
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=node(0);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}
void modify(int x,int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=node(1);
		return;
	}
	int h=l+r>>1;
	if(x<=h)
		modify(x,k<<1,l,h);
	else
		modify(x,k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}
node query(int L,int R,int k=1,int l=1,int r=n){
	if(L>R)
		return em;
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1;
	node o=em;
	if(L<=h)
		o=o+query(L,R,k<<1,l,h);
	if(h<R)
		o=o+query(L,R,k<<1|1,h+1,r);
	return o;
}
int a[N],b[N],c[N],d[N],e[N],tt,p[N];
vector<int> v[N],h[N],v1[N],v2[N];
void dfs1(int u,int fa){
	int i,x;
	a[u]=fa;
	b[u]=1;
	d[u]=d[fa]+1;
	for(i=v[u].size();i--;){
		x=v[u][i];
		if(x==fa)
			continue;
		v1[h[u][i]].push_back(x);
		dfs1(x,u);
		b[u]+=b[x];
		if(b[x]>b[c[u]])
			c[u]=x;
	}
}
void dfs2(int u,int fa,int w){
	int i,x;
	p[u]=++tt;
	e[u]=w;
	if(c[u])
		dfs2(c[u],u,e[u]);
	for(i=v[u].size();i--;){
		x=v[u][i];
		if(x==fa||x==c[u])
			continue;
		dfs2(x,u,x);
	}
}
int m,w[N];
int qx[N],qy[N],qs[N];
int lb(int x){
	return lower_bound(w,w+m,x)-w;
}
node qu(int x,int y){
	if(e[x]==e[y]){
		if(d[x]<d[y])
			return query(p[x]+1,p[y]);
		return rev(query(p[y]+1,p[x]));
	}
	else{
		if(d[e[x]]<d[e[y]])
			return qu(x,a[e[y]])+query(p[e[y]],p[y]);
		return rev(qu(y,a[e[x]])+query(p[e[x]],p[x]));
	}
}
int main()
{
	em.e=1;
	int i,j,x,y,z;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i=i+1)
		scanf("%d",f+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		w[m++]=z;
		v[x].push_back(y);
		h[x].push_back(z);
		v[y].push_back(x);
		h[y].push_back(z);
	}
	sort(w,w+m);
	m=unique(w,w+m)-w;
	for(i=1;i<=n;i=i+1)
		for(j=v[i].size();j--;)
			h[i][j]=lb(h[i][j]);
	dfs1(1,0);
	dfs2(1,0,1);
	build();
	for(i=1;i<=q;i=i+1){
		scanf("%d%d%d",qx+i,qy+i,&z);
		v2[lb(z)].push_back(i);
	}
	for(i=m;i>=0;i=i-1){
		for(j=v1[i].size();j--;)
			modify(p[v1[i][j]]);
		for(j=v2[i].size();j--;){
			z=v2[i][j];
			qs[z]=qu(qx[z],qy[z]).ans();
		}
	}
	for(i=1;i<=q;i=i+1)
		cout<<qs[i]<<endl;
	return 0;
}