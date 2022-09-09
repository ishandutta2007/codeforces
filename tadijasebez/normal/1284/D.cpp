#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
int x[N],y[N],a[N],b[N];
bool Check(int n)
{
	vector<pair<int,int>> evs;
	for(int i=1;i<=n;i++)
	{
		evs.pb({x[i],i});
		evs.pb({y[i]+1,-i});
	}
	sort(evs.begin(),evs.end());
	multiset<int> l,r;
	int p=-1,cnt=0;
	for(auto e:evs)
	{
		int t=e.first;
		int id=e.second;
		if(p<t && cnt>0)
		{
			if(*r.begin()<*l.rbegin()) return 0;
		}
		p=t;
		if(id>0) l.insert(a[id]),r.insert(b[id]),cnt++;
		else id=-id,l.erase(l.find(a[id])),r.erase(r.find(b[id])),cnt--;
	}
	return 1;
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i %i %i %i",&x[i],&y[i],&a[i],&b[i]);
	if(!Check(n)) printf("NO\n");
	else
	{
		for(int i=1;i<=n;i++) swap(x[i],a[i]),swap(y[i],b[i]);
		if(Check(n)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}