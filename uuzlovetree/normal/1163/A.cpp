#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
bool vis[1005];
int main()
{
	scanf("%d%d",&n,&m);
	if(!m)
	{
		printf("1\n");
	}
	else if(m<=n/2)
	{
		printf("%d\n",m);
	}
	else
	{
		printf("%d\n",n-m);
	}
	return 0;
}