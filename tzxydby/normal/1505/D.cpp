#include<bits/stdc++.h>
using namespace std;
int n,m,v[20];
int main()
{
	scanf("%d%d",&n,&m);
	while(n)
	{
		if(v[n%m])
		{
			puts("NO");
			return 0;
		}
		v[n%m]=1;
		n/=m;
	}
	puts("YES");
	return 0;
}