#include <bits/stdc++.h>
using namespace std;
#define ldb long double
#define pb push_back
#define mp make_pair
const ldb eps=1e-14;
const int N=200050;
pair<int,int> p[N];
set<pair<int,int> > st,sol;
vector<pair<ldb,ldb> > pts,hull;
ldb Orientation(pair<ldb,ldb> p, pair<ldb,ldb> q, pair<ldb,ldb> r)
{
	return (q.second-p.second)*(r.first-q.first)-(q.first-p.first)*(r.second-q.second);	
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&p[i].first,&p[i].second);
		if(st.find(p[i])==st.end())
		{
			pts.pb(mp((ldb)100/p[i].first,(ldb)100/p[i].second));
			st.insert(p[i]);
		}
	}
	sort(pts.begin(),pts.end());
	for(i=0;i<pts.size();i++)
	{
		while(hull.size()>1 && Orientation(hull[hull.size()-2],hull.back(),pts[i])>eps) hull.pop_back();
		hull.push_back(pts[i]);
	}
	while(hull.size()>1 && hull[hull.size()-2].second-hull.back().second<eps) hull.pop_back();
	for(i=0;i<hull.size();i++) sol.insert(mp((int)round((ldb)100.0/hull[i].first),(int)round((ldb)100.0/hull[i].second)));
	for(i=1;i<=n;i++) if(sol.count(p[i])) printf("%i ",i);
	printf("\n");
	return 0;
}