//CF 48G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,vis[N],b[N],d[N],t[N];
LL ans[N];
vector<int> v[N],h[N];
int s=0,f=0,a[N],e[N],se[N],ee;
int nxt(int i){
	return (i+1)%s;
}
int prv(int i){
	return (i-1+s)%s;
}
int getl(int l,int r){
	if(l<=r)
		return se[r]-se[l];
	return ee-se[l]+se[r];
}
void dfs1(int u,int fa){
	//cout<<u<<fa<<endl;
	if(vis[u]){
		reverse(a,a+s);
		while(a[s-1]!=u){
			a[--s]=0;
		}
		f=1;
		return;
	}
	vis[u]=1;
	a[s++]=u;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa)
			dfs1(x,u);
		if(f)
			return;
	}
	a[--s]=0;
}
int dfs2(int u,int fa){
	t[u]=1;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa&&!b[x]){
			d[x]=d[u]+h[u][i];
			t[u]+=dfs2(x,u);
		}
	}
	return t[u];
}
void dfs3(int u,int fa){
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa&&!b[x]){
			ans[x]=ans[u];
			ans[x]+=h[u][i]*(n-t[x]-t[x]);
			dfs3(x,u);
		}
	}
}
int main()
{
	int i,x,y,z;
	LL ss=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y);
		h[x].push_back(z);
		v[y].push_back(x);
		h[y].push_back(z);
	}
	dfs1(1,0);
	for(i=0;i<s;i=i+1)
		b[a[i]]=1;//,cout<<a[i];
	for(i=0;i<s;i=i+1)
		dfs2(a[i],0);
	for(i=1;i<=n;i=i+1)
		ss+=d[i];
	for(i=0;i<s;i=i+1){
		x=v[a[i]].size();
		while(x--){
			if(v[a[i]][x]==a[prv(i)])
				e[i]=h[a[i]][x];
		}
		if(i)
			se[i]=se[i-1]+e[i];
		ee+=e[i];
		ss+=(LL)se[i]*t[a[i]];
	}
	y=0;
	x=s-1;
	i=0;
	//cout<<ee;
	while(i!=x&&getl(x,i)<getl(i,x)){
		ss+=(LL)t[a[x]]*(getl(x,i)-getl(i,x));
		y+=t[a[x]];
		x=prv(x);
	}
	x=nxt(x);
	ans[a[0]]=ss;
	for(i=1;i<s;i=i+1){
		//cout<<ss<<x<<y<<endl;
		if(i==x){
			y-=t[a[x]];
			x=prv(x);
			ss+=(LL)t[a[i]]*(getl(x,i)-getl(i,x));
			x=nxt(i);
		}
		//cout<<ss<<x<<y<<endl;
		y+=t[a[i-1]];
		ss-=(LL)e[i]*(n-y-y);
		//cout<<ss<<x<<y<<endl;
		while(getl(x,i)>getl(i,x)){
			ss-=(LL)t[a[x]]*(getl(x,i)-getl(i,x));
			y-=t[a[x]];
			x=nxt(x);
		}
		ans[a[i]]=ss;
		//cout<<ss<<x<<y<<endl;
	}
	for(i=0;i<s;i=i+1)
		dfs3(a[i],0);
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}