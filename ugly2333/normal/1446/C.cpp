//CF1446C
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
const int N = 1<<23;
int n,tot,rt,ls[N],rs[N],f[N];
void ins(int&k,int x,int d){
	if(!k)
		k=++tot;//cout<<k<<x<<d<<endl;
	if(d<0)
		return;
	if(x&(1<<d))
		ins(rs[k],x,d-1);
	else
		ins(ls[k],x,d-1);
}
void dfs(int u){
	if(!u)
		return;
	dfs(ls[u]);
	dfs(rs[u]);
	if(ls[u]&&rs[u])
		f[u]=max(f[ls[u]],f[rs[u]])+1;
	else
		f[u]=max(f[ls[u]],f[rs[u]]);
}
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		ins(rt,x,30);
	}
	dfs(rt);
	cout<<n-f[rt]-1;
	return 0;
}