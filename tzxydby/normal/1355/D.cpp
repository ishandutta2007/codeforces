#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	if(n-1>=s-n)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<n;i++)
			printf("1 ");
		printf("%d\n",s-n+1);
		printf("%d\n",s-n);
	}	
	return 0;
}