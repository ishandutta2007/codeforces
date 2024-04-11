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
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
int a[N],b[N],id[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),id[a[i]]=i;
	for(int i=1;i<=n;i++) scanf("%i",&b[i]),b[i]=id[b[i]];
	int ans=0;
	for(int i=n,mn=n+1;i>=1;i--)
	{
		//printf("%i ",b[i]);
		mn=min(mn,b[i]);
		if(mn!=b[i]) ans++;
	}
	printf("%i\n",ans);
	return 0;
}