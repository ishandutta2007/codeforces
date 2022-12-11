#include <bits/stdc++.h>
using namespace std;
int n,a,b,x;
bool check=false;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (x=0;x<=n/a;x++)
		if ((n-x*a)%b==0) 
		{
			check=true;
			break;
		}
	if (!check) printf("NO\n");
	else
	{
		printf("YES\n");
		printf("%d %d\n",x,(n-x*a)/b);
	}
	return 0;
}