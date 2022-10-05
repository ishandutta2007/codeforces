#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,m,x[Maxn],y[Maxn],cnt;
bool vis[Maxn];
bool prim(int num)
{
	if(vis[num]) return false;
	int maxi=sqrt(num);
	for(int i=2;i<=maxi;i++)
		if(num%i==0)
		{
			vis[num]=true;
			return false;
		}
	return true;
}
int main()
{
	scanf("%d",&n);
	m=n;
	for(int i=1;i<=n;i++)
		x[i]=i,y[i]=i%n+1;
	for(int i=1;i<=n;i++)
		if(!prim(m)) x[++m]=i,y[m]=n-i;
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}