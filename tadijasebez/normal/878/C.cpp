#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
int m;
struct Component
{
	int l[10],r[10],sz;
	void Make_Component(){ sz=1;for(int i=0;i<m;i++) scanf("%i",&l[i]),r[i]=l[i];}
	inline Component operator + (const Component &b) const
	{
		Component c;
		c.sz=sz+b.sz;
		int i;
		for(i=0;i<m;i++) c.l[i]=min(l[i],b.l[i]),c.r[i]=max(r[i],b.r[i]);
		return c;
	}
	inline bool operator < (const Component &b) const{ for(int i=0;i<m;i++) if(r[i]>b.l[i]) return false; return true;}
	inline bool operator == (const Component &b) const{ return (*this<b && b<*this) || !(*this<b || b<*this);}
} Tmp;
set<Component> Set;
set<Component>::iterator it1,it2,it3;
int Solve()
{
	Tmp.Make_Component();
	it1=Set.lower_bound(Tmp);
	it2=Set.upper_bound(Tmp);
	for(it3=it1;it3!=it2;it3++) Tmp=Tmp+*it3;
	Set.erase(it1,it2);
	Set.insert(Tmp);
	return Set.rbegin()->sz;
}
int main()
{
	int n;scanf("%i %i",&n,&m);
	while(n--) printf("%i\n",Solve());
	return 0;
}