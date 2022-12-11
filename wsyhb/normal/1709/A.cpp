#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,a[4];
		scanf("%d%d%d%d",&x,&a[1],&a[2],&a[3]);
		if(a[1]==1||a[2]==2||a[3]==3||!a[x])
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}