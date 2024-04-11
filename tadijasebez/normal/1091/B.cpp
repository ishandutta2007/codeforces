#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
	vector<pair<int,int> > o,c;
	set<pair<int,int> > has;
	int n,i;
	scanf("%i",&n);o.resize(n+1);c.resize(n+1);
	for(i=1;i<=n;i++) scanf("%i %i",&o[i].first,&o[i].second);
	for(i=1;i<=n;i++) scanf("%i %i",&c[i].first,&c[i].second),has.insert(c[i]);
	for(i=1;i<=n;i++)
	{
		pair<int,int> T=mp(o[1].first+c[i].first,o[1].second+c[i].second);
		bool ok=1;
		for(int j=1;j<=n;j++)
		{
			pair<int,int> tmp=mp(T.first-o[j].first,T.second-o[j].second);
			if(!has.count(tmp)){ ok=0;break;}
		}
		if(ok)
		{
			printf("%i %i\n",T.first,T.second);
			return 0;
		}
	}
	//printf("-1\n");
	return 0;
}