#include <bits/stdc++.h>
using namespace std;
int q,l,r;
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		long long ans=0;
		scanf("%d%d",&l,&r);
		l--;
		printf("%d\n",((r/2)-((r%2)?r:0))-((l/2)-((l%2)?l:0)));
	}
	return 0;
}