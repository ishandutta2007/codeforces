//CF 165D
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
const int N = 111111;
vector<int> v[N];
int n,rt,m;
int ex[N],ey[N],d[N];
int nt,h[N],sz[N];
vector<int> t[N];
void dfs(int u,int fa){
	int i,s,x;
	s=v[u].size();
	if(u==rt)
		d[u]=0;
	else
		d[u]=d[fa]+1;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
	if(u!=rt){
		if(s==1){
			++nt;
			t[nt].push_back(0);
		}
		h[u]=nt;
	}
}
void addv(int x,int v,int i){
	while(x<=sz[i]){
		t[i][x]+=v;
		x+=x&-x;
	}
}
int gtsum(int x,int i){
	int res;
	res=0;
	while(x){
		res+=t[i][x];
		x-=x&-x;
	}
	return res;
}
int main()
{
	int m,i,x,y,z,yy,zz,ans;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		ex[i]=x;
		ey[i]=y;
	}
	rt=n;
	for(i=1;i<n;i=i+1)
		if(v[i].size()>2)
			rt=i;
	dfs(rt,0);
	for(i=1;i<n;i=i+1)
		if(d[ex[i]]>d[ey[i]])
			swap(ex[i],ey[i]);
	for(i=1;i<=n;i=i+1){
		if(i==rt)
			continue;
		sz[h[i]]++;
		t[h[i]].push_back(0);
		//cout<<h[i]<<d[i]<<endl;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if(x==3){
			ans=-1;
			scanf("%d",&z);
			yy=gtsum(d[y],h[y]);
			zz=gtsum(d[z],h[z]);
			//cout<<yy<<zz<<endl;
			if(y==rt||z==rt||h[y]==h[z]){
				if(yy==zz)
					ans=max(d[y]-d[z],d[z]-d[y]);
			}
			else{
				if(yy+zz==0)
					ans=d[y]+d[z];
			}
			cout<<ans<<endl;
		}
		else{
			y=ey[y];
			if(x==1)
				addv(d[y],-1,h[y]);
			if(x==2)
				addv(d[y],1,h[y]);
		}
	}
	return 0;
}