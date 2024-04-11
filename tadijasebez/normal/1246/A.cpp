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
	int n,p;
	scanf("%i %i",&n,&p);
	for(int i=0;(n-p*i)>0;i++)
	{
		int m=n-p*i;
		int pc=__builtin_popcount(m);
		//printf("%i %i %i\n",m,pc,i);
		if(pc<=i && m>=i)
		{
			printf("%i\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}