#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define pb push_back
const int N=100050;
int x[N],y[N];
struct Card
{
	int a,b,t;
	Card(int x=0, int y=0, int z=0){ a=x,b=y,t=z;}
	bool operator < (Card c) const { return (a+b)>(c.a+c.b) || (a+b)==(c.a+c.b) && t<c.t;}
};
int main()
{
	int n,i,a,b,c,d;
	vector<Card> all;
	scanf("%i",&n);
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i %i",&a,&b,&c,&d);
		x[i]=a+b;
		y[i]=c+d;
		if(x[i]>=y[i]) all.pb(Card(a,b,0)),all.pb(Card(c,d,1));
		else sol+=max(a-d,min(0,c-b));
	}
	sort(all.begin(),all.end());
	for(i=0;i<all.size();i++)
	{
		if(i&1) sol-=all[i].b;
		else sol+=all[i].a;
	}
	printf("%lld\n",sol);
	return 0;
}