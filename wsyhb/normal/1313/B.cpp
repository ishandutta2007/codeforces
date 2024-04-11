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
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		printf("%d %d\n",max(1,min(n,x+y-n+1)),min(n,x+y-1));
	}
	return 0;
}