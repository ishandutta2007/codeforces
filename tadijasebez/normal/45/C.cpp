#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=200050;
set<int> pos;
set<int>::iterator it1,it3;
set<pair<int,pair<int,int> > > ord;
set<pair<int,pair<int,int> > >::iterator it2;
char s[N];
vector<pair<int,int> > sol;
int GetNext(int x){ it3=pos.upper_bound(x);if(it3==pos.end()) return 0;return *it3;}
int GetPrev(int x){ it3=pos.lower_bound(x);if(it3==pos.begin()) return 0;it3--;return *it3;}
int a[N];
int val(int x, int y){ int ret=a[x]-a[y];if(ret<0) ret*=-1;return ret;}
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),pos.insert(i);
	for(i=1;i<n;i++) if(s[i]!=s[i+1]) ord.insert(mp(val(i,i+1),mp(i,i+1)));
	while(ord.size())
	{
		pair<int,pair<int,int> > tmp=*ord.begin();
		ord.erase(tmp);
		sol.pb(tmp.second);
		int x=tmp.second.first;
		int y=tmp.second.second;
		pos.erase(x);
		pos.erase(y);
		int v=GetPrev(x);
		if(v && s[v]!=s[x]) ord.erase(mp(val(v,x),mp(v,x)));
		int z=GetNext(y);
		if(z && s[z]!=s[y]) ord.erase(mp(val(y,z),mp(y,z)));
		if(v && z && s[z]!=s[v]) ord.insert(mp(val(v,z),mp(v,z))); 
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}