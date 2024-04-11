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
ll Ask(int t, int i, int j, int k)
{
	printf("%i %i %i %i\n",t,i,j,k);
	fflush(stdout);
	ll b;
	scanf("%lld",&b);
	return b;
}
const int N=1050;
ll Area[N];
int main()
{
	int n;
	scanf("%i",&n);
	int mn=2;
	for(int i=3;i<=n;i++) if(Ask(2,1,mn,i)==-1) mn=i;
	for(int i=2;i<=n;i++) if(i!=mn) Area[i]=Ask(1,1,mn,i);
	int mx=-1;
	for(int i=2;i<=n;i++) if(i!=mn && (mx==-1 || Area[i]>Area[mx])) mx=i;
	vector<int> L,R;
	for(int i=2;i<=n;i++) if(i!=mn && i!=mx)
	{
		ll b=Ask(2,1,mx,i);
		if(b==-1) L.pb(i);
		else R.pb(i);
	}
	sort(L.begin(),L.end(),[&](int i, int j){ return Area[i]<Area[j];});
	sort(R.begin(),R.end(),[&](int i, int j){ return Area[i]>Area[j];});
	vector<int> ans;
	ans.pb(1);
	ans.pb(mn);
	for(int i:L) ans.pb(i);
	ans.pb(mx);
	for(int i:R) ans.pb(i);
	printf("0 ");
	for(int i:ans) printf("%i ",i);
	printf("\n");
	fflush(stdout);
	return 0;
}