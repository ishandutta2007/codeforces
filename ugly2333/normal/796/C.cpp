//CF 798B
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
vector<int> v[333333];
pair<int,int> a[333333];
int f[333333],g[333333],b[333333];
int main()
{
	int n,i,u,x,y,ans,s;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&a[i].first);
		b[i]=a[i].first;
		a[i].second=i;
		g[i]=-1<<30;
	}
	if(n==1){
		cout<<a[1].first<<endl;
		return 0;
	}
	for(i=1;i<n;i=i+1)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		g[x]=max(g[x],a[y].first);
		g[y]=max(g[y],a[x].first);
	}
	sort(a+1,a+n+1);
	a[0]=make_pair(-1<<30,0);
	ans=1<<30;
	for(u=1;u<=n;u=u+1){
		for(i=0;i<v[u].size();i=i+1)
			f[v[u][i]]=1;
		f[u]=1;
		i=n;
		while(i>0&&f[a[i].second]){
			i=i-1;
		}
		ans=min(ans,max(max(a[i].first+2,g[u]+1),b[u]));
		//cout<<a[i].first+2<<' '<<g[u]+1<<' '<<b[u]<<endl;
		for(i=0;i<v[u].size();i=i+1)
			f[v[u][i]]=0;
		f[u]=0;
	}
	cout<<ans<<endl;
	return 0;
}
/*
7
38 -29 87 93 39 28 -55
1 2
2 5
3 2
2 4
1 7
7 6

*/