#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int a,b,n;
bool check(int t)
{
	int k=a/t+b/t;
	if(a<t || b<t) return 0;
	if(k>=n) return 1;
	return 0;
}
int main()
{
	scanf("%i %i %i",&n,&a,&b);
	int top=a+b;
	int bot=1,ans=0;
	while(top>=bot)
	{
		int mid=top+bot>>1;
		if(check(mid)) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	printf("%i\n",ans);
	return 0;
}