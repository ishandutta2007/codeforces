#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,m;
int c[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int x,i=1;i<=m;++i)scanf("%d",&x),c[x]++;
	for(int T=1;T<=1000;++T)
	{
		int tot=0;
		for(int i=1;i<=100;++i)tot+=c[i]/T;
		if(tot<n)
		{
			printf("%d\n",T-1);
			return 0;
		}
	}
	return 0;
}