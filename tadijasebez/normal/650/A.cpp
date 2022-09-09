#include <stdio.h>
#include <map>
using namespace std;
map<int,int> hor,ver;
map<pair<int,int>,int> cnt;
long long sol;
int main()
{
	int q,x,y;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&x,&y);
		sol+=hor[x]+ver[y]-cnt[make_pair(x,y)];
		hor[x]++;
		ver[y]++;
		cnt[make_pair(x,y)]++;
	}
	printf("%lld\n",sol);
}