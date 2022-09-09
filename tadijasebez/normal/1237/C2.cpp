#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
map<int,map<int,vector<pair<int,int>>>> pts;
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%i %i %i",&x,&y,&z);
		pts[x][y].pb({z,i});
	}
	vector<pair<int,int>> ans;
	vector<int> X;
	for(auto it:pts)
	{
		vector<int> Y;
		for(auto jt:it.second)
		{
			vector<pair<int,int>> p=jt.second;
			sort(p.begin(),p.end());
			for(int i=0;i+1<p.size();i+=2)
			{
				ans.pb({p[i].second,p[i+1].second});
			}
			if(p.size()&1) Y.pb(p.back().second);
		}
		for(int i=0;i+1<Y.size();i+=2)
		{
			ans.pb({Y[i],Y[i+1]});
		}
		if(Y.size()&1) X.pb(Y.back());
	}
	for(int i=0;i+1<X.size();i+=2)
	{
		ans.pb({X[i],X[i+1]});
	}
	for(auto e:ans) printf("%i %i\n",e.first,e.second);
	return 0;
}