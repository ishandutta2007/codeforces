//CF 930A
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
typedef double DB;
const int N = 111111;
int n,p[N],d[N],s[N];
vector<int> v[N];
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	s[d[u]]^=1;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
int main()
{
	int i,ans=0;
	scanf("%d",&n);
	for(i=2;i<=n;i=i+1)
		scanf("%d",p+i),v[p[i]].push_back(i);
	dfs(1,0);
	for(i=1;i<=n;i=i+1)
		ans+=s[i];
	cout<<ans;
	return 0;
}