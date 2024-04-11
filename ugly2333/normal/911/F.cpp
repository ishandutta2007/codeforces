//CF 911F
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
const int N = 222222;
int n,d[N],f,a[N][3],t;
LL ans;
vector<int> v[N],h;
void dfs1(int u,int fa=0){
	int i,sz,x;
	d[u]=d[fa]+1;
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i];
		if(x!=fa)
			dfs1(x,u);
	}
}
void dfs2(int u,int b,int fa=0){
	int i,sz,x;
	h.push_back(u);
	if(u==b){
		f=1;
		return;
	}
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i];
		if(x!=fa)
			dfs2(x,b,u);
		if(f)
			return;
	}
	h.pop_back();
}
void ANS(int x,int y){
	t++;
	a[t][0]=x,a[t][1]=y,a[t][2]=y;
}
void dfs3(int u,int b,int fa=0){
	int i,sz,x,w=0;
	if(!d[u])
		d[u]=d[fa]+1,w=1;
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i];
		if(x!=fa&&!d[x])
			dfs3(x,b,u);
	}
	if(w){
		ANS(b,u);
		ans+=(LL)d[u];
	}
}
int main()
{
	int i,x,y,s;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1);
	s=0;
	for(i=1;i<=n;i=i+1)
		if(s<d[i])
			s=d[i],x=i;
	dfs1(x);
	s=0;
	for(i=1;i<=n;i=i+1)
		if(s<d[i])
			s=d[i],y=i;
	memset(d,0,sizeof(d));
	dfs2(x,y);
	s=h.size()-1;
	for(i=0;i<=s;i=i+1)
		d[h[i]]=max(i,s-i);
	for(i=0;i<=s;i=i+1){
		if(i>=s-i)
			dfs3(h[i],x);
		else
			dfs3(h[i],y);
	}
	for(i=0;i<s;i=i+1)
		ANS(y,h[i]),ans+=(LL)s-i;
	cout<<ans<<endl;
	for(i=1;i<n;i=i+1){
		for(s=0;s<=2;s=s+1)
			cout<<a[i][s]<<' ';
		cout<<endl;
	}
	return 0;
}