#include <bits/stdc++.h>
using namespace std;
int a[7],p[7];
int main()
{
	int i;
	for(i=1;i<=6;i++) scanf("%i",&a[i]);
	for(i=4;i<=6;i++) p[i]=1;
	do
	{
		int x=0,y=0;
		for(i=1;i<=6;i++)
		{
			if(p[i]) x+=a[i];
			else y+=a[i];
		}
		if(x==y) return 0*printf("YES\n");
	}while(next_permutation(p+1,p+7));
	printf("NO\n");
	return 0;
}