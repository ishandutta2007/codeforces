#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
set<int>s;
int x,y,g,t;
int main()
{
	s.insert(0);
	scanf("%d %d",&x,&y);
	g=__gcd(x,y);
	for(int i=1;i*i<=g;i++)
		if(g%i==0)
		{
			s.insert(i);
			s.insert(g/i);
		}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&x,&y);
		int t=*--s.upper_bound(y);
		printf("%d\n",x>t?-1:t);
	}
	return 0;
}