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

int main()
{
	int n;
	scanf("%i",&n);
	bool flag=0;
	while(n--)
	{
		int x;
		scanf("%i",&x);
		if(x%2==0) printf("%i\n",x/2);
		else
		{
			if(flag) x=ceil((ldb)x/2);
			else x=floor((ldb)x/2);
			printf("%i\n",x);
			flag^=1;
		}
	}
	return 0;
}