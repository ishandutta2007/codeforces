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
int mx[N],mn[N],id[N],dp[N*10];
vector<int> seq[N];
bool ok[N];
int main()
{
	int n;
	scanf("%i",&n);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int l;
		scanf("%i",&l);
		seq[i].resize(l);
		mn[i]=1e6+7;
		bool ok=0;
		for(int &j:seq[i])
		{
			scanf("%i",&j);
			if(j>mn[i]) ok=1;
			ckmn(mn[i],j),ckmx(mx[i],j);
		}
		if(!ok) dp[mx[i]]++;
		else cnt++;
		id[i]=i;
		::ok[i]=ok;
		//printf("%i %i %i\n",ok,mn[i],mx[i]);
	}
	for(int i=1e6;i>=0;i--) dp[i]+=dp[i+1];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ok[i]) ans+=n;
		else
		{
			ans+=cnt+dp[mn[i]+1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}