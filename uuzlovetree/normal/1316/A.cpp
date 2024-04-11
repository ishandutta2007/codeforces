#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		int s=0;
		for(int x,i=1;i<=n;++i)scanf("%d",&x),s+=x;
		printf("%d\n",min(m,s));
	}
}