// CF 338B
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
int a[111111],f[111111],t[111111],p[111111];
vector<int> v[111111];
int dfs(int u,int fa)
{
	int i;
	for(i=0;i<v[u].size();i=i+1)
		if(v[u][i]!=fa)
			t[u]=max(t[u],dfs(v[u][i],u)+1);
	return t[u];
}
void dfs2(int u,int fa)
{
	int i,s,ss,j;
	s=-1<<30;
	ss=-1<<30;
	for(i=0;i<v[u].size();i=i+1){
		j=v[u][i];
		if(j!=fa){
			if(t[j]>=s){
				ss=s;
				s=t[j];
			}
			else{
				if(t[j]>=ss)
					ss=t[j];
			}
		}
	}
	for(i=0;i<v[u].size();i=i+1){
		j=v[u][i];
		if(j!=fa){
			if(t[j]<s||ss==s)
				p[j]=s+2;
			else
				p[j]=ss+2;
			p[j]=max(p[j],p[u]+1);
			if(f[j])
				p[j]=max(p[j],0);
			dfs2(j,u);
		}
	}
}
int main()
{
	int n,m,d,i,x,y;
	cin>>n>>m>>d;
	for(i=1;i<=m;i=i+1){
		cin>>a[i];
		f[a[i]]=i;
		t[a[i]]=1;
	}
	v[1].push_back(0);
	for(i=1;i<n;i=i+1){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1){
		if(t[i]!=1)
			t[i]=-1<<30;
		else
			t[i]=0;
		p[i]=t[i];
	}
	t[1]=dfs(1,0);
	dfs2(1,0);
	x=0;
	for(i=1;i<=n;i=i+1){
		//cout<<i<<' '<<t[i]<<' '<<p[i]<<endl;
		if(t[i]<=d&&p[i]<=d)
			x++;
	}
	cout<<x<<endl;
	return 0;
}