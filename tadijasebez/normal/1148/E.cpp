#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=300050;
int a[N],p[N],my[N],id[N];
set<pair<int,int>> all;
vector<pair<pair<int,int>,int>> ans;
/*bool Solve(int n)
{
	sort(p+1,p+1+n);
    int l=1,r=n;
    while(l<=r)
	{
		if(l==r)
		{
			if(all.begin()->first!=p[l]) return 0;
			else break;
		}
		pair<int,int> L=*all.begin();
		pair<int,int> R=*all.rbegin();
		all.erase(all.begin());
		all.erase(--all.end());
		if(p[l]<L.first || p[r]>R.first) return 0;
		int mov=min(p[l]-L.first,R.first-p[r]);
		L.first+=mov;
		R.first-=mov;
		if(mov>0) ans.pb({{L.second,R.second},mov});
		if(p[l]!=L.first) all.insert(L);
		else l++;
		if(p[r]!=R.first) all.insert(R);
		else r--;
	}
	return 1;
}
void Test()
{

}*/
int main()
{
	//Test();
	//return 0;
	int n,i;
	scanf("%i",&n);
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		int x;
		scanf("%i",&x);
		all.insert({x,i});
		sum+=x;
	}
	for(i=1;i<=n;i++) scanf("%i",&p[i]),sum-=p[i];
	if(sum!=0) return 0*printf("NO\n");
    sort(p+1,p+1+n);
    auto it=all.begin();
    for(int i=1;i<=n;i++)
	{
		my[it->second]=i;
		a[it->second]=p[i]-it->first;
		id[i]=i;
		it++;
	}
	sort(id+1,id+1+n,[&](int x, int y){ return my[x]<my[y];});
	int j=1;
	for(int i=1;i<=n;i++)
	{
		if(a[id[i]]<0) return 0*printf("NO\n");
		while(a[id[i]]>0)
		{
			while(j<=n && a[id[j]]>=0) j++;
			int mov=min(a[id[i]],-a[id[j]]);
			ans.pb({{id[i],id[j]},mov});
			a[id[i]]-=mov;
			a[id[j]]+=mov;
		}
	}
    /*int l=1,r=n;
    while(l<=r)
	{
		if(l==r)
		{
			//if(all.begin()->first!=p[l]) return 0*printf("NO\n");
			//else break;
			break;
		}
		pair<int,int> L=*all.begin();
		pair<int,int> R=*all.rbegin();
		all.erase(all.begin());
		all.erase(--all.end());
		if(p[l]<L.first || p[r]>R.first) return 0*printf("NO\n");
		int mov=min(p[l]-L.first,R.first-p[r]);
		L.first+=mov;
		R.first-=mov;
		if(mov>0) ans.pb({{L.second,R.second},mov});
		if(p[l]!=L.first) all.insert(L);
		else l++;
		if(p[r]!=R.first) all.insert(R);
		else r--;
	}*/
	printf("YES\n");
	printf("%i\n",ans.size());
	for(auto p:ans) printf("%i %i %i\n",p.first.first,p.first.second,p.second);
	return 0;
}