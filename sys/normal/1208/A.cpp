#include <bits/stdc++.h>
using namespace std;
int T,n,a,b;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&n);
		if(n%3==1) printf("%d\n",b);
		else if(n%3==2) printf("%d\n",a^b);
		else printf("%d\n",a);
	}
	return 0;
}