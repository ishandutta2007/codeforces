//CF1656B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,a[N];
vector<int> v[N];
void dfs(int u,int fa){
	a[u]=-a[fa];
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
int main()
{
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
			
		}
		a[0]=1;
		dfs(1,0);
		for(i=1;i<=n;i++)
			printf("%d ",a[i]*v[i].size());
		printf("\n");
		for(i=1;i<=n;i++)
			v[i].clear(),a[i]=0;
	}
	return 0;
}