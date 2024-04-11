// CF 812E
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
int a[111111],p[111111],d[111111];
vector<int> v[111111];
map<int,int> M;
void dfs(int k)
{
	int i;
	if(v[k].size()==0){
		d[k]=1;
		return;
	}
	for(i=0;i<v[k].size();i=i+1){
		dfs(v[k][i]);
	}
	d[k]=1-d[v[k][0]];
}
int main()
{
	int n,i,sg,s;
	LL ans;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=2;i<=n;i=i+1){
		cin>>p[i];
		v[p[i]].push_back(i);
	}
	dfs(1);
	sg=0;
	s=0;
	for(i=1;i<=n;i=i+1){
		if(d[i]==1){
			sg^=a[i];
			s++;
		}
	}
	for(i=1;i<=n;i=i+1){
		if(d[i]==1){
			M[sg^a[i]]++;
		}
	}
	ans=0;
	if(sg==0){
		ans+=(LL)s*(s-1);
		s=n-s;
		ans+=(LL)s*(s-1);
		s=n-s;
		ans/=(LL)2;
	}
	for(i=1;i<=n;i=i+1){
		if(d[i]==0){
			ans+=(LL)M[a[i]];
		}
	}
	cout<<ans<<endl;
	return 0;
}