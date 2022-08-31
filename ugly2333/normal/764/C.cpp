//CF 764C
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
vector<int> g[100005];
int f[100005],c[100005],s[100005],cc[100005],a[100005];
bool b[100005];
int dfs(int k,int fa)
{
	int i,x;
	f[k]=fa;
	a[k]=c[k];
	s[k]=1;
	for(i=0;i<g[k].size();i=i+1){
		if(g[k][i]!=fa){
			x=dfs(g[k][i],k);
			s[k]=s[k]+s[g[k][i]];
			//cout<<x<<' '<<c[k]<<endl;
			if(x==c[k])
				continue;
			a[k]=-1;
			//cout<<a[k]<<endl;
		}
	}
	return a[k];
}
int main()
{
	int n,i,x,y,j,sc,csc;
	cin>>n;
	for(i=1;i<n;i=i+1)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1){
		cin>>c[i];
		cc[c[i]]++;
	}
	sc=0;
	for(i=1;i<=100001;i=i+1)
		if(cc[i]!=0)
			sc=sc+1;
	if(dfs(1,0)!=-1){
		cout<<"YES\n1\n";
		return 0;
	}
	for(i=1;i<=n;i=i+1)
	{
		x=1;
		for(j=0;j<g[i].size();j=j+1){
			if(g[i][j]!=f[i]&&a[g[i][j]]==-1){
				x=0;
			}
		}
		if(x==0)
			continue;
		if(i==1){
			cout<<"YES\n1\n";
			return 0;
		}
		csc=sc;
		for(j=0;j<g[i].size();j=j+1){
			if(g[i][j]!=f[i]){
				cc[a[g[i][j]]]-=s[g[i][j]];
				if(cc[a[g[i][j]]]==0)
					csc=csc-1;
			}
		}
		cc[c[i]]--;
		if(cc[c[i]]==0)
			csc=csc-1;
		//cout<<csc<<endl;
		if(csc<=1){
			cout<<"YES\n"<<i<<endl;
			return 0;
		}
		for(j=0;j<g[i].size();j=j+1)
			if(g[i][j]!=f[i])
				cc[a[g[i][j]]]+=s[g[i][j]];
		cc[c[i]]++;
	}
	cout<<"NO"<<endl;
	return 0;
}
/*
4
1 2
2 3
3 4
1 2 1 1
*/