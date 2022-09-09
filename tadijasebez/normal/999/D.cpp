#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define mp make_pair
#define ll long long
const int N=200050;
//set<pair<int,int> > sz;
//set<int> my[N];
set<int> work;
int Find(int x)
{
	if(work.upper_bound(x)==work.end()) return *work.begin();
	else return *work.upper_bound(x);
}
int a[N],cnt[N];
int main()
{
	int n,i,m,k;
	scanf("%i %i",&n,&m);
	k=n/m;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),cnt[a[i]%m]++;
	ll sol=0;
	for(i=0;i<m;i++) if(cnt[i]<k) work.insert(i);
	for(i=1;i<=n;i++)
	{
		int g=a[i]%m;
		if(cnt[g]>k)
		{
			cnt[g]--;
			int nu=Find(g);
			int sz;
			if(nu<g) sz=m-g+nu;
			else sz=nu-g;
			sol+=sz;
			a[i]+=sz;
			cnt[nu]++;
			if(cnt[nu]==k) work.erase(nu);
		}
	}
	/*for(i=0;i<m;i++) sz.insert(mp(cnt[i],i));
	int sol=0;
	while(sz.rbegin()->first!=k)
	{
		int go=sz.rbegin()->second;
		sz.erase(--sz.end());
		cnt[go]--;
		sz.insert(mp(cnt[go],go));
		int id=*my[go].begin();
		my[go].erase(id);
		a[id]++;
		int nu=(go+1)%m;
		my[nu].insert(id);
		sz.erase(mp(cnt[nu],nu));
		cnt[nu]++;
		sz.insert(mp(cnt[nu],nu));
		sol++;
	}*/
	printf("%lld\n",sol);
	for(i=1;i<=n;i++) printf("%i ",a[i]);
	return 0;
}