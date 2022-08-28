//CF 1037D
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
int n,a[N],b[N],c[N],d[N],f[N];
vector<int> v[N];
queue<int> q;
void dfs(int u,int fa){
	f[u]=fa;
	for(int i=v[u].size();i--;)
		if(v[u][i]!=fa)
			dfs(v[u][i],u);
}
int main()
{
	int i,j,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	x=(a[1]==1);
	q.push(1);
	for(i=2;x&&i<=n;i=i+1){
		while(!q.empty()&&f[a[i]]!=q.front()){
			q.pop();
		}
		if(q.empty())
			x=0;
		q.push(a[i]);
	}
	if(x)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}