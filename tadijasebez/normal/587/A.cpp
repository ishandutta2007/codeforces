#include <stdio.h>
#include <set>
using namespace std;
multiset<int> s;
multiset<int>::iterator it;
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),s.insert(x);
	int sol=0;
	while(s.size()>1)
	{
		it=s.begin();
		x=*it;
		it++;
		y=*it;
		s.erase(s.begin());
		if(x==y)
		{
			s.erase(s.begin());
			s.insert(x+1);
		}
		else sol++;
	}
	printf("%i\n",sol+1);
	return 0;
}