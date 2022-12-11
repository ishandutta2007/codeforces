#include<bits/stdc++.h>
using namespace std;
int T,n,m; 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n%m==0)puts("YES");
		else puts("NO");
	}
}