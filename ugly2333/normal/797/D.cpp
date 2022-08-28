//CF 797D
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
int v[111111],l[111111],r[111111],f[111111],o[111111],s;
void dfs(int u,int lo,int hi)
{
	if(u==-1||lo>hi)
		return;
	if(v[u]>=lo&&v[u]<=hi){
		s++;
		o[s]=v[u];
	}
	dfs(l[u],lo,min(v[u],hi));
	dfs(r[u],max(v[u],lo),hi);
}
int main()
{
	int n,i,j,rt,ans;
	cin>>n;
	for(i=1;i<=n;i=i+1)
	{
		scanf("%d%d%d",&v[i],&l[i],&r[i]);
		if(l[i]!=-1)
			f[l[i]]=i;
		if(r[i]!=-1)
			f[r[i]]=i;
	}
	for(i=1;i<=n;i=i+1)
		if(f[i]==0)
			rt=i;
	dfs(rt,-1,1<<30);
	s++;
	o[s]=1<<30;
	sort(o+1,o+s+1);
	//for(i=1;i<=s;i=i+1)
	//	cout<<o[i]<<endl;
	sort(v+1,v+n+1);
	ans=0;
	i=1;
	j=1;
	while(i<=n&&j<=s){
		//cout<<v[i]<<o[j]<<ans<<endl;
		if(v[i]==o[j])
			i++;
		else{
			if(v[i]<o[j]){
				ans++;
				i++;
			}
			else
				j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
10
9 -1 -1
8 -1 -1
1 -1 9
10 10 2
4 6 3
3 8 7
2 4 1
6 -1 -1
5 -1 -1
7 -1 -1
*/