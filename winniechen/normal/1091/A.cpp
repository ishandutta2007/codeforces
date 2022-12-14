#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int y,b,r,ans=1<<30;
	scanf("%d%d%d",&y,&b,&r);
	ans=min(r-2,min(b-1,y));
	printf("%d\n",ans*3+3);
}