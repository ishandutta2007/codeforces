#include<bits/stdc++.h>
int main()
{
	int t,s,x;
	scanf("%d%d%d",&t,&s,&x);
	if (x==t+1||x<t)
	{
		printf("NO");
		return 0;
	}
	if ((x-t)%s==0||(x-t)%s==1)
		printf("YES");
	else
		printf("NO");
	return 0;
}