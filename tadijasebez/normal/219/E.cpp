#include <stdio.h>
#include <set>
using namespace std;
#define mp make_pair
set<pair<int,pair<int,int> > > ord;
set<pair<int,int> > all;
set<pair<int,int> >::iterator it1;
const int M=1000050;
int pos[M],n;
void Insert(int l, int r)
{
	if(l>r) return;
	all.insert(mp(l,r));
	if(l==1 || r==n) ord.insert(mp(-(r-l+1),mp(l,r)));
	else ord.insert(mp(-(r-l+2)/2,mp(l,r)));
}
void Delete(int l, int r)
{
	if(l>r) return;
	all.erase(mp(l,r));
	if(l==1 || r==n) ord.erase(mp(-(r-l+1),mp(l,r)));
	else ord.erase(mp(-(r-l+2)/2,mp(l,r)));
}
pair<int,int> Next(int x)
{
	it1=all.upper_bound(mp(x,M));
	if(it1==all.end() || it1->first>x+1) return mp(0,-1);
	else return *it1;
}
pair<int,int> Prev(int x)
{
	it1=all.lower_bound(mp(x,0));
	if(it1==all.begin() || (--it1)->second<x-1) return mp(0,-1);
	return *it1;
}
int main()
{
	int m,i,t,x;
	scanf("%i %i",&n,&m);
	all.insert(mp(1,n));
	ord.insert(mp(-n,mp(1,n)));
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&t,&x);
		if(t==1)
		{
			pair<int,int> seg=ord.begin()->second;
			//printf("->%i\n",-ord.begin()->first);
			ord.erase(ord.begin());
			all.erase(seg);
			//printf("(%i %i)\n",seg.first,seg.second);
			if(seg.first==1)
			{
				pos[x]=1;
				Insert(2,seg.second);
			}
			else if(seg.second==n)
			{
				pos[x]=n;
				Insert(seg.first,n-1);
			}
			else
			{
				pos[x]=seg.first+seg.second>>1;
				Insert(seg.first,pos[x]-1);
				Insert(pos[x]+1,seg.second);
			}
			printf("%i\n",pos[x]);
		}
		else
		{
			pair<int,int> L=Prev(pos[x]),R=Next(pos[x]);
			if(L.first && R.first)
			{
				Delete(L.first,L.second);
				Delete(R.first,R.second);
				Insert(L.first,R.second);
			}
			else if(L.first)
			{
				Delete(L.first,L.second);
				Insert(L.first,pos[x]);
			}
			else if(R.first)
			{
				Delete(R.first,R.second);
				Insert(pos[x],R.second);
			}
			else
			{
				Insert(pos[x],pos[x]);
			}
		}
	}
	return 0;
}