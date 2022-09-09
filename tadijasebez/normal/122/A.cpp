
// Problem : A. Lucky Division
// Contest : Codeforces Beta Round #91 (Div. 2 Only)
// URL : https://codeforces.com/problemset/problem/122/A
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
	int n;
	scanf("%i",&n);
	set<int> lucky={4,7,44,47,74,77,47,444,447,474,477,744,747,774,777};
	for(int l:lucky)if(n%l==0)return 0*printf("YES\n");
	printf("NO\n");
	return 0;
}