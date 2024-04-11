#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
const int N=200050;
const int inf=1e9+7;
pair<int,int> min(pair<int,int> a, pair<int,int> b){ return a>b?b:a;}
set< pair<int,int> > Set[N];
set< pair<int,int> >::iterator it;
vector<int> id;
void Add(int x, int y)
{
	int i=lower_bound(id.begin(),id.end(),y)-id.begin()+1;
	for(;i;i-=i&-i) Set[i].insert(mp(x,y));
}
void Err(int x, int y)
{
	int i=lower_bound(id.begin(),id.end(),y)-id.begin()+1;
	for(;i;i-=i&-i) Set[i].erase(mp(x,y));
}
void Get(int x, int y)
{
	int i=lower_bound(id.begin(),id.end(),y)-id.begin()+2;
	pair<int,int> ret=mp(inf,inf);
	for(;i<N;i+=i&-i)
	{
		it=Set[i].upper_bound(mp(x,inf));
		if(it==Set[i].end()) continue;
		ret=min(ret,*it);
	}
	if(ret!=mp(inf,inf)) printf("%i %i\n",ret.first,ret.second);
	else printf("-1\n");
}
char ch[N][20];
int x[N],y[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%s %i %i",&ch[i],&x[i],&y[i]),id.push_back(y[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++)
	{
		if(ch[i][0]=='a') Add(x[i],y[i]);
		if(ch[i][0]=='r') Err(x[i],y[i]);
		if(ch[i][0]=='f') Get(x[i],y[i]);
	}
	return 0;
}