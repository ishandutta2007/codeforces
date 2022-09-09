#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int inf=1000000000;
set< pair<ll,int> > Set;
set< pair<ll,int> >::iterator it;
vector< pair<ll,int> > Lower;
const int N=300050;
ll T[N],W[N];
int sol=inf,c;
int min(int a, int b){ return a>b?b:a;}
bool comp(pair<ll,int> a, pair<ll,int> b){ return a.first>b.first;}
void Consider()
{
	while(c<Lower.size() && T[1]<Lower[c].first) 
		Set.insert(make_pair(W[Lower[c].second]-T[Lower[c].second]+1,Lower[c].second)),c++;
}
bool Try()
{
	Consider();
	sol=min(sol,Set.size()+1);
	it=Set.begin();
	if(it->first>T[1]) return false;
	T[1]-=it->first;
	Set.erase(*it);
} 
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%lld %lld",&T[1],&W[1]);
	for(i=2;i<=n;i++)
	{
		scanf("%lld %lld",&T[i],&W[i]);
		Lower.push_back(make_pair(T[i],i));
	}
	sort(Lower.begin(),Lower.end(),comp);
	while(Try());
	printf("%i\n",sol);
	return 0;
}