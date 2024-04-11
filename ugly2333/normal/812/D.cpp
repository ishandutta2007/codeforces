// CF 812D
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
int a[111111],b[111111],c[111111],f[111111],u[111111],t,tb[111111],te[111111],s[111111];
vector<int> v[111111];
void dfs(int k){
	if(u[k])
		return;
	u[k]=1;
	s[k]=1;
	t++;
	tb[k]=t;
	int i;
	for(i=0;i<v[k].size();i=i+1){
		if(!u[v[k][i]]){
			dfs(v[k][i]);
			s[k]+=s[v[k][i]];
		}
	}
	t++;
	te[k]=t;
}
int main()
{
	int n,m,k,q,i,x,y;
	cin>>n>>m>>k>>q;
	for(i=1;i<=k;i=i+1){
		cin>>a[i]>>b[i];
		if(c[b[i]]){
			v[c[b[i]]].push_back(a[i]);
			f[a[i]]=1;
		}
		c[b[i]]=a[i];
	}
	t=0;
	for(i=1;i<=n;i=i+1)
		if(!u[i]&&!f[i])
			dfs(i);
	for(i=1;i<=q;i=i+1)
	{
		cin>>x>>y;
		y=c[y];
		if(y==0){
			cout<<"0\n";
			continue;
		}
		if(tb[x]<tb[y]&&te[x]>te[y])
			cout<<s[x]<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}