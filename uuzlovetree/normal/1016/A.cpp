#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,m;
int a[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ll now=0;
	for(int i=1;i<=n;++i)
	{
		now+=a[i];
		printf("%d ",now/m);
		now%=m;
	}
	return 0;
}