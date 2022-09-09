#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<pair<int,int> ,pair<int,int> > best;
vector<int> v;
int sol,first,second;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int x,y,z,i,n;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		v.clear();
		scanf("%i %i %i",&x,&y,&z);
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
		sort(v.begin(),v.end());
		if(v[0]>sol)
		{
			first=i;
			second=-1;
			sol=v[0];
		}
		if(min(v[1],v[0]+best[make_pair(v[1],v[2])].first)>sol)
		{
			sol=min(v[1],v[0]+best[make_pair(v[1],v[2])].first);
			first=i;
			second=best[make_pair(v[1],v[2])].second;
		}
		if(v[0]>best[make_pair(v[1],v[2])].first)
		{
			best[make_pair(v[1],v[2])].first=v[0];
			best[make_pair(v[1],v[2])].second=i;
		}
	}
	if(second==-1) printf("1\n%i\n",first);
	else printf("2\n%i %i\n",first,second);
	return 0;
}