#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int a,b,ans,x,y;
int main()
{
	scanf("%d%d",&a,&b);
	if(a>b)swap(a,b);
	while(a!=b)
	{
		if(x<=y)
		{
			x++;
			ans+=x;
			a++;
		}else
		{
			y++;
			ans+=y;
			b--;
		}
	}
	printf("%d\n",ans);
	return 0;
}