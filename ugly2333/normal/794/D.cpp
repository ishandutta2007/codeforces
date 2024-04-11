//CF 794D
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
const int mod = 1000*1000*1000+9;
const int b1 = 131;
const int b2 = 137;
vector<int> v[333333],g[333333];
pair<pair<int,int>,int> p[333333];
int c[333333],f[333333];
int main()
{
	int n,m,i,x,y,j;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1){
		v[i].push_back(i);
		c[i]=i;
	}
	for(i=1;i<=m;i=i+1)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1)
		sort(v[i].begin(),v[i].end());
	for(i=1;i<=n;i=i+1)
	{
		x=0;
		y=0;
		for(j=0;j<v[i].size();j=j+1){
			//cout<<v[i][j]<<x<<endl;
			x=((long long)(b1*x)+v[i][j])%mod;
			y=((long long)(b2*y)+v[i][j])%mod;
		}
		//cout<<x<<' '<<y<<' '<<i<<endl;
		p[i]=make_pair(make_pair(x,y),i);
	}
	sort(p+1,p+n+1);
	j=1;
	for(i=1;i<=n;i=i+1)
	{
		if(p[i].first==p[j].first){
			c[p[i].second]=p[j].second;
			//cout<<p[i].second<<p[j].second<<endl;
		}
		else
			j=i;
	}
	if(j==1){
		cout<<"YES\n";
		for(i=1;i<=n;i=i+1)
			cout<<"1 ";
		cout<<endl;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		for(j=0;j<v[i].size();j=j+1)
			if(c[i]!=c[v[i][j]]){
				g[c[i]].push_back(c[v[i][j]]);
				g[c[v[i][j]]].push_back(c[i]);
			}
	x=0;
	y=0;
	for(i=1;i<=n;i=i+1)
	{
		//cout<<c[i]<<endl;
		if(g[i].size()){
			sort(g[i].begin(),g[i].end());
			j=unique(g[i].begin(),g[i].end())-g[i].begin();
			g[i].resize(j);
			if(g[i].size()>2){
				cout<<"NO\n";
				return 0;
			}
			if(g[i].size()==1){
				x++;
				y=i;
			}
		}
	}
	if(x!=2)
	{
		cout<<"NO\n";
		return 0;
	}
	f[y]=1;
	for(i=2;i<=n;i=i+1){
		//cout<<y<<f[y]<<endl;
		for(j=0;j<g[y].size();j=j+1){
			//cout<<y<<g[y][j]<<' ';
			if(f[g[y][j]]==0){
				y=g[y][j];
				break;
			}
		}
		f[y]=i;
		if(g[y].size()==1)
			break;
	}
	cout<<"YES\n";
	for(i=1;i<=n;i=i+1)
		cout<<f[c[i]]<<' ';
	cout<<"\n";
	return 0;
}