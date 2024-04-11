#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
struct op
{
	int t,k;char d;
	op(int _t){ t=_t;}
	op(int _k, char _d){ t=1;k=_k;d=_d;}
	void Print()
	{
		if(t==1) printf("1 %i %c\n",k,d);
		else printf("%i\n",t);
	}
};
vector<op> sol;
vector<pair<int,int> > bombs;
int abs(int x){ return x>0?x:-x;}
bool comp(pair<int,int> a, pair<int,int> b)
{
	return mp(abs(a.first),abs(a.second))<mp(abs(b.first),abs(b.second));
}
int main()
{
	int n,x,y,i;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i",&x,&y);
		bombs.pb(mp(x,y));
	}
	sort(bombs.begin(),bombs.end(),comp);
	for(i=0;i<bombs.size();i++)
	{
		x=bombs[i].first;
		y=bombs[i].second;
		if(x<0) sol.pb(op(-x,'L'));
		if(x>0) sol.pb(op(x,'R'));
		if(y<0) sol.pb(op(-y,'D'));
		if(y>0) sol.pb(op(y,'U'));
		sol.pb(op(2));
		if(y<0) sol.pb(op(-y,'U'));
		if(y>0) sol.pb(op(y,'D'));
		if(x<0) sol.pb(op(-x,'R'));
		if(x>0) sol.pb(op(x,'L'));
		sol.pb(op(3));
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) sol[i].Print();
	return 0;
}