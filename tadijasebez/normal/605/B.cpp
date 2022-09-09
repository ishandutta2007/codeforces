#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const int N=100050;
pair<int,int> sol[N];
struct Edge
{
	int w,i,t;
	Edge(){}
	Edge(int a, int b, int c){ w=a,i=b,t=c;}
	inline bool operator < (const Edge &b) const
	{
		if(w==b.w) return t>b.t;
		return w<b.w;
	}
};
vector<Edge> E;
map<int,bool> used[N];
set< pair<int,int> > Free;
set< pair<int,int> >::iterator it;
int c=1;
int main()
{
	int n,m,w,t,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&w,&t),E.push_back(Edge(w,i,t));
	sort(E.begin(),E.end());
	for(i=0;i<E.size();i++)
	{
		if(E[i].t==0)
		{
			if(Free.empty()) return printf("-1\n"),0;
			it=Free.begin();
			sol[E[i].i]=*it;
			Free.erase(*it);
		}
		else
		{
			c++;
			if(c<1000)
			{
				for(j=1;j<c-1;j++) Free.insert(make_pair(j,c));
			}
			sol[E[i].i]=make_pair(c-1,c);
		}
	}
	for(i=1;i<=m;i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}