#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int x=min(n/k,m);
		m-=x;
		printf("%d\n",x-(m+k-2)/(k-1));
	}
	return 0;
}