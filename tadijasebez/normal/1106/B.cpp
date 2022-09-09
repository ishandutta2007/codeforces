#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
struct Kind
{
	int c,id;
	Kind(int x=0, int y=0):c(x),id(y){}
	bool operator < (Kind b) const { return mp(c,id)<mp(b.c,b.id);}
};
const int N=100050;
int r[N],c[N];
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	set<Kind> all;
	for(i=1;i<=n;i++) scanf("%i",&r[i]);
	for(i=1;i<=n;i++) scanf("%i",&c[i]),all.insert(Kind(c[i],i));
	while(m--)
	{
		int t,sz;
		scanf("%i %i",&t,&sz);
		ll cost=0;
		int eat=min(sz,r[t]);
		sz-=eat;
		r[t]-=eat;
		cost+=(ll)c[t]*eat;
		while(all.size() && sz>0)
		{
			t=all.begin()->id;
			eat=min(sz,r[t]);
			sz-=eat;
			r[t]-=eat;
			cost+=(ll)c[t]*eat;
			if(r[t]==0) all.erase(all.begin());
		}
		if(sz!=0) cost=0;
		printf("%lld\n",cost);
	}
	return 0;
}