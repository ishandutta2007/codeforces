//CF 791D
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
int n,k,f[200005],t[200005];
long long in[200005][5],out[200005][5];
vector<int> v[200005];
void dfs(int u,int fa)
{
	f[u]=fa;
	t[u]=1;
	int i;
	for(i=0;i<v[u].size();i=i+1)
		if(v[u][i]!=fa){
			dfs(v[u][i],u);
			t[u]=t[u]+t[v[u][i]];
		}
}
void dfs2(int u)
{
	int s,i,j,p;
	s=v[u].size();
	out[u][0]=1;
	if(s==1)
		return;
	for(i=0;i<s;i=i+1){
		if(v[u][i]==f[u])
			continue;
		dfs2(v[u][i]);
		for(j=0;j<k;j=j+1){
			for(p=0;p<k;p=p+1){
				in[u][(j+p+1)%k]+=out[u][j]*out[v[u][i]][p];
			}
		}
		for(j=0;j<k;j=j+1){
			out[u][(j+1)%k]+=out[v[u][i]][j];
			in[u][j]+=in[v[u][i]][j];
		}
	}
}
int main()
{
	int i,x,y;
	long long s;
	cin>>n>>k;
	for(i=1;i<n;i=i+1){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	v[1].push_back(0);
	dfs(1,0);
	s=0;
	for(i=2;i<=n;i=i+1)
		s=s+(long long)t[i]*(n-t[i]);
	if(k==1){
		cout<<s<<endl;
		return 0;
	}
	dfs2(1);
	for(i=1;i<k;i=i+1)
		s=s+(long long)(k-i)*in[1][i];
	/*for(i=1;i<=n;i=i+1){
		for(x=0;x<k;x=x+1)
			cout<<out[i][x]<<' ';
		cout<<endl;
	}*/
	cout<<s/(long long)k<<endl;
	return 0;
}