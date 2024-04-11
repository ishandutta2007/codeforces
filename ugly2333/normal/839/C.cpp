//CF 839C
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
vector<int> v[111111];
double dfs(int u,int fa){
	int i,s;
	double res;
	s=v[u].size();
	if(s==1)
		return 0;
	res=0;
	for(i=0;i<s;i=i+1){
		if(v[u][i]!=fa)
			res+=dfs(v[u][i],u)+1;
	}
	s--;
	res/=s;
	return res;
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	v[1].push_back(0);
	printf("%.9lf",dfs(1,0));
	return 0;
}