#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a[4];
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
		int x=(a[0]>a[1]?0:1),y=(a[2]>a[3]?2:3);
		if(a[x]>a[y])
			puts(a[y]>a[1-x]?"YES":"NO");
		else
			puts(a[x]>a[5-y]?"YES":"NO");
	}
	return 0;
}