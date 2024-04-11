#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
map<ll,set<pair<int,int> > > all;
pair<int,int> operator + (pair<int,int> a, pair<int,int> b)
{
	int x=a.first+b.first,y=a.second+b.second;
	int g=__gcd(x,y);
	x/=g,y/=g;
	return mp(x,y);
}
map<pair<int,int> ,int> ans;
void Add(pair<int,int> p)
{
	ll sq=(ll)p.first*p.first+(ll)p.second*p.second;
	for(auto l:all[sq]) ans[p+l]+=2;
	all[sq].insert(p);
	ans[p+mp(0,0)]++;
}
void Rem(pair<int,int> p)
{
	ll sq=(ll)p.first*p.first+(ll)p.second*p.second;
	all[sq].erase(p);
	for(auto l:all[sq]) ans[p+l]-=2;
	ans[p+mp(0,0)]--;
}
int main()
{
	int q,t,x,y,sz=0;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&x,&y);
		if(t==1) Add(mp(x,y)),sz++;
		if(t==2) Rem(mp(x,y)),sz--;
		if(t==3) printf("%i\n",sz-ans[mp(x,y)+mp(0,0)]);
	}
	return 0;
}