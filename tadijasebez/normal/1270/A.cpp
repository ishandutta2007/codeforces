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
		int n,k1,k2;
		scanf("%i %i %i",&n,&k1,&k2);
		int x;
		bool ok=0;
		while(k1--)
		{
			scanf("%i",&x);
			if(x==n) ok=1;
		}
		while(k2--) scanf("%i",&x);
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}