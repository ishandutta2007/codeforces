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
pair<int,int> Ask(vector<int> v)
{
	printf("? ");
	for(int i:v) printf("%i ",i);
	printf("\n");
	fflush(stdout);
	pair<int,int> b;
	scanf("%i %i",&b.first,&b.second);
	return b;
}
const int N=100050;
int a[N];
bool was[N];
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	vector<int> mid;
	vector<int> v;
	for(int i=1;i<=k;i++) v.pb(i);
	pair<int,int> o=Ask(v);
	a[o.first]=o.second;
	was[o.first]=1;
	mid.pb(o.first);
	for(int i=k+1;i<=n;i++)
	{
		for(int j=0;j<k;j++) if(was[v[j]]){ v[j]=i;break;}
		o=Ask(v);
		a[o.first]=o.second;
		was[o.first]=1;
		mid.pb(o.first);
	}
	int lo=mid[1],hi=mid[0];
    if(a[mid[0]]<a[mid[1]]) swap(lo,hi);
    int ban_p;
    for(int i=0;i<k;i++) if(was[v[i]]) ban_p=i;
    v[ban_p]=lo;
    int ans=0;
    for(int i=0;i<k;i++) if(i!=ban_p)
	{
		int tmp=v[i];
		v[i]=hi;
		o=Ask(v);
		if(o.first==hi) ans++;
		v[i]=tmp;
	}
	printf("! %i\n",ans+1);
	fflush(stdout);
	return 0;
}