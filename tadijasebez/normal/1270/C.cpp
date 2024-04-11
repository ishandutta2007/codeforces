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

int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n;
		scanf("%i",&n);
		vector<int> a(n);
		ll sum=0,xr=0;
		for(int &i:a) scanf("%i",&i),sum+=i,xr^=i;
		ll u=((ll)1)<<55;
		if(sum&1) u++;
		xr^=u;
		xr*=2;
		sum+=u;
		ll f=(xr-sum)/2;
		printf("3\n%lld %lld %lld\n",u,f,f);
	}
	return 0;
}