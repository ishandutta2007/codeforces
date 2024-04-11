#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=min(a,b);i;i--)
	 if (a/i+b/i>=n)
	  {
	  	printf("%d\n",i);
	  	return 0;
	  }
}