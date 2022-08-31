//CF 825E
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
int indeg[111111],ans[111111];
priority_queue<int> Q;
int main()
{
	int n,m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[y].push_back(x);
		indeg[x]++;
	}
	for(i=1;i<=n;i=i+1){
		if(!indeg[i])
			Q.push(i);
	}
	y=n;
	while(!Q.empty()){
		x=Q.top();
		Q.pop();
		ans[x]=y;
		y--;
		for(i=0;i<v[x].size();i=i+1){
			indeg[v[x][i]]--;
			if(!indeg[v[x][i]])
				Q.push(v[x][i]);
		}
	}
	for(i=1;i<=n;i=i+1)
		printf("%d ",ans[i]);
	return 0;
}