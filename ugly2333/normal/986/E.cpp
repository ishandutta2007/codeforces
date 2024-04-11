//CF 986E
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
const int A = 1e7;
const int MO = 1e9+7;
void MUL(int& x,int y){
	x=(LL)x*y%MO;
}
int fpow(int x,int y){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	MUL(z,z);
	if(y&1)
		MUL(z,x);
	return z;
}
int n,a[N],m,pr[N];
int tt,tin[N],tout[N],d[N],f[N][22],s[N];
vector<int> v[N];
int q,qx[N],qy[N],qa[N],qz[N],ans[N];
vector<pair<int,int> > vn[A+1],vq[A+1];
void dfs0(int u,int fa){
	int i;
	d[u]=d[fa]+1;
	f[u][0]=fa;
	tin[u]=++tt;
	for(i=v[u].size();i--;){
		if(v[u][i]!=fa)
			dfs0(v[u][i],u);
	}
	tout[u]=tt;
}
void dfs1(int u,int fa){
	s[u]+=s[fa];
	int i;
	for(i=v[u].size();i--;){
		if(v[u][i]!=fa)
			dfs1(v[u][i],u);
	}
}
int lca(int x,int y){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=18;d[x]>d[y];j=j-1)
		if(d[f[x][j]]>=d[y])
			x=f[x][j];
	if(x==y)
		return x;
	for(j=18;f[x][0]!=f[y][0];j=j-1)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
int isin(int x,int y){
	return tin[y]<=tin[x]&&tout[x]<=tout[y];
}
int chk(int u,int i){
	return isin(u,qz[i])&&(isin(qx[i],u)||isin(qy[i],u));
}
int main()
{
	int i,j,k,x,y,w,e;
	for(i=2;i*i<=A;i=i+1){
		x=1;
		for(j=2;j*j<=i;j=j+1)
			if(i%j==0)
				x=0;
		if(x)
			pr[++m]=i;
	}
	
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs0(1,0);
	for(j=1;j<=18;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		y=a[i];
		for(j=1;j<=m;j=j+1){
			x=1;
			while(y%pr[j]==0){
				y/=pr[j];
				x*=pr[j];
			}
			if(x>1)
				vn[pr[j]].push_back(make_pair(i,x));
		}
		if(y>1)
			vn[y].push_back(make_pair(i,y));
	}
	
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d%d",qx+i,qy+i,qa+i);
		qz[i]=lca(qx[i],qy[i]);
		ans[i]=1;
		y=qa[i];
		for(j=1;j<=m;j=j+1){
			x=1;
			while(y%pr[j]==0){
				y/=pr[j];
				x*=pr[j];
			}
			if(x>1)
				vq[pr[j]].push_back(make_pair(i,x));
		}
		if(y>1)
			vq[y].push_back(make_pair(i,y));
	}
	
	for(i=2;i<=A;i=i+1){
		x=vn[i].size();
		y=vq[i].size();
		if(!x||!y)
			continue;
		if((LL)x*y<=N){
			for(j=0;j<x;j=j+1)	
				for(k=0;k<y;k=k+1)
					if(chk(vn[i][j].first,vq[i][k].first))
						MUL(ans[vq[i][k].first],min(vn[i][j].second,vq[i][k].second));
		}
		else{
			w=i;
			for(j=1;1;j=j+1){
				memset(s,0,sizeof(s));
				for(k=0;k<x;k=k+1)
					if(vn[i][k].second==w)
						s[vn[i][k].first]=1;
				dfs1(1,0);
				for(k=0;k<y;k=k+1){
					e=vq[i][k].first;
					MUL(ans[e],fpow(min(w,vq[i][k].second),s[qx[e]]+s[qy[e]]-s[qz[e]]-s[f[qz[e]][0]]));
				}
				if((LL)w*i>(LL)A)
					break;
				w*=i;
			}
		}
	}
	for(i=1;i<=q;i=i+1)
		printf("%d\n",ans[i]);
	return 0;
}