#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int x=3;
		while(n%x) x=x<<1|1;
		printf("%d\n",n/x);
	} 
	return 0;
}