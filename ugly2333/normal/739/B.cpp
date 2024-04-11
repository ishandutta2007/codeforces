//CF 739B
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
const int N = 222222;
int a[N],f[N],c[N],ans[N],sh;
vector<int> v[N];
LL h[N];
int p[N];
void dfs(int u){
	int i,s,x;
	sh++;
	h[sh]=(LL)h[sh-1]+c[u];
	p[sh]=u;
	x=lower_bound(h+1,h+sh+1,h[sh]-a[u])-h;
	ans[f[p[x]]]--;
	ans[f[u]]++;
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		dfs(x);
		ans[u]+=ans[x];
	}
	sh--;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=2;i<=n;i=i+1){
		scanf("%d%d",f+i,c+i);
		v[f[i]].push_back(i);
	}
	h[0]=0;
	p[0]=0;
	sh=0;
	dfs(1);
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}