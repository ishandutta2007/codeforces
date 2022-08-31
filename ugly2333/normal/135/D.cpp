//CF135D
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
const int N = 1011;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char ch[N];
int n,m,ans,k,f,t,a[N][N],b[N][N],c[N][N],d[N][N],e[N][N];
vector<pair<int,int> > v,p;
void dfs0(int i,int j){
	if(a[i][j]<0)
		f=1;
	if(a[i][j]||b[i][j])
		return;
	b[i][j]=k;
	v.push_back(make_pair(i,j));
	int x,y;
	for(x=i-1;x<=i+1;x=x+1)
		for(y=j-1;y<=j+1;y=y+1)
			dfs0(x,y);
}
void go(int i,int j){
	int x,y;
	for(x=i-1;x<=i+1;x=x+1)
		for(y=j-1;y<=j+1;y=y+1)
			if(a[x][y]&&c[x][y]!=k)
				c[x][y]=k,p.push_back(make_pair(x,y));
}
void chk(int i,int j){
	int s=0,o;
	for(o=0;o<4;o=o+1)
		if(c[i+dx[o]][j+dy[o]]==k)
			s++;
	if(s!=2)
		f=1;
}
void dfs1(int i,int j){
	if(a[i][j]!=1||c[i][j]!=k||d[i][j]==k)
		return;
	d[i][j]=k;
	t++;
	int o;
	for(o=0;o<4;o=o+1)
		dfs1(i+dx[o],j+dy[o]);
}
void dfs2(int i,int j){
	if(b[i][j]!=k&&c[i][j]!=k)
		return;
	if(e[i][j]==k)
		return;
	e[i][j]=k;
	int o;
	for(o=0;o<4;o=o+1){
		if(!a[i][j]&&a[i+dx[o]][j+dy[o]]&&c[i+dx[o]][j+dy[o]]!=k)
			f=1;
		dfs2(i+dx[o],j+dy[o]);
	}
}
int main()
{
	int i,j,l,o,s;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n+1;i=i+1)
		for(j=0;j<=m+1;j=j+1)
			a[i][j]=-1;
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		for(j=1;j<=m;j=j+1)
			a[i][j]=ch[j]-'0';
	}
	for(i=1;i<n;i=i+1)
		for(j=1;j<m;j=j+1)
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
				ans=4;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1){
			if(a[i][j]||b[i][j])
				continue;
			v.clear();
			f=0;
			k++;
			dfs0(i,j);
			if(f)
				continue;
			o=v.size();
			p.clear();
			for(l=0;l<o;l=l+1)
				go(v[l].first,v[l].second);
			o=p.size();
			for(l=0;l<o;l=l+1)
				chk(p[l].first,p[l].second);
			if(f)
				continue;
			t=0;
			dfs1(p[0].first,p[0].second);
			if(t!=o)
				continue;
			dfs2(v[0].first,v[0].second);
			if(f)
				continue;
			ans=max(ans,o);
		}
	}
	cout<<ans;
	return 0;
}