//CF 587C
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
const int Q = 19;
const int A = 10;
int d[N];
vector<int> a[N],v[N],t;
int f[N][Q+5];
vector<int> s[N][Q+5];
void dfs(int u,int fa){
	int i,w;
	f[u][0]=fa;
	d[u]=d[fa]+1;
	w=v[u].size();
	for(i=0;i<w;i=i+1){
		if(v[u][i]!=fa)
			dfs(v[u][i],u);
	}
}
void addt(int x,int y){
	int p,k;
	p=s[x][y].size();
	for(k=0;k<p&&k<A;k=k+1)
		t.push_back(s[x][y][k]); 
}
int main()
{
	int n,m,q,i,j,x,y,z,p,k;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d",&x);
		s[x][0].push_back(i);
	}
	dfs(n,0);
	for(j=1;j<=Q;j=j+1)
		for(i=1;i<=n;i=i+1){
			p=f[i][j-1];
			f[i][j]=f[p][j-1];
			x=s[i][j-1].size();
			y=s[p][j-1].size();
			t.clear();
			addt(i,j-1);
			addt(p,j-1);
			sort(t.begin(),t.end());
			for(k=0;k<x+y&&k<A&&t[k]!=0;k=k+1)
				s[i][j].push_back(t[k]);
		}
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		t.clear();
		if(d[x]<d[y])
			swap(x,y);
		j=Q;
		while(d[x]>d[y]){
			if(d[f[x][j]]>=d[y]){
				addt(x,j);
				x=f[x][j];
				//cout<<j<<endl;
			}
			j--;
		}
		if(x!=y){
			j=Q;
			while(f[x][0]!=f[y][0]){
				if(f[x][j]!=f[y][j]){
					addt(x,j);
					addt(y,j);
					x=f[x][j];
					y=f[y][j];
				}
				j--;
			}
			addt(x,0);
			addt(y,0);
			x=f[x][0];
			y=f[y][0];
		}
		addt(x,0);
		sort(t.begin(),t.end());
		p=t.size();
		cout<<min(p,z);
		for(k=0;k<p&&k<z;k=k+1)
			cout<<' '<<t[k];
		cout<<endl;
	}
	return 0;
}