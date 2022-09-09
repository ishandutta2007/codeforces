#include <stdio.h>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
const int N=2050;
struct Point
{
	int x,y;
	inline ll operator + (const Point &b) const
	{
		return (ll)(x-b.x)*(x-b.x)+(ll)(y-b.y)*(y-b.y);
	}
	inline int operator - (const Point &b) const
	{
		if(x<b.x) return y-b.y;
		if(x>b.x) return b.y-y;
		return abs(y-b.y);
	}
} p[N];
map<ll,vector<int> > mapa;
ll sol;
int main()
{
	int i,j,n;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i %i",&p[i].x,&p[i].y);
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) mapa[p[i]+p[j]].push_back(p[i]-p[j]);
	map<ll,vector<int> >::iterator it;
	for(it=mapa.begin();it!=mapa.end();it++)
	{
		vector<int> tmp=it->second;
		sort(tmp.begin(),tmp.end());
		j=1;
		for(i=1;i<tmp.size();i++)
		{
			if(tmp[i]!=tmp[i-1])
			{
				sol+=(ll)j*(j-1)/2;
				j=0;
			}
			j++;
		}
		sol+=(ll)j*(j-1)/2;
	}
	printf("%lld\n",sol/2);
	return 0;
}