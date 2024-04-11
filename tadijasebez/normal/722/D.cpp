#include <stdio.h>
#include <set>
using namespace std;
set<int> Set;
set<int>::iterator it;
int main()
{
	int n,i,x,t=1;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&x),Set.insert(-x);
	while(t)
	{
		t=0;
		x=-(*Set.begin());
		while(x>1)
		{
			x/=2;
			if(!Set.count(-x))
			{
				t=1;
				Set.erase(*Set.begin());
				Set.insert(-x);
				break;
			}
		}
	}
	for(it=Set.begin();it!=Set.end();it++) printf("%i ",-(*it));
	printf("\n");
	return 0;
}