
// Problem : A. Deadline
// Contest : Educational Codeforces Round 80 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1288/problem/A
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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
		int n,x;
		scanf("%i %i",&n,&x);
		int lo=sqrt(x)-100;
		int hi=sqrt(x)+100,ans=x;
		for(int i=lo;i<=hi;i++)
		{
			if(i>=0 && i<=x)
			{
				ans=min(ans,i+(x+i)/(i+1));
			}
		}
		if(ans<=n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}