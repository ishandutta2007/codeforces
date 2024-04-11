#include <bits/stdc++.h>
using namespace std;
int q,n,l,r;
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&n);
		if(l>n) printf("%d\n",n);
		else printf("%d\n",r-r%n+n);
	}
	return 0;
}