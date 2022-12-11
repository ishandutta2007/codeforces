#include<bits/stdc++.h>
using namespace std;
int n,m;
bitset<10005> A[55];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
		{
			int x;
			scanf("%d",&x);
			A[i][x]=1;
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)if((A[i]&A[j]).count()==0)
		{
			puts("impossible");
			return 0;
		}
	puts("possible");
}