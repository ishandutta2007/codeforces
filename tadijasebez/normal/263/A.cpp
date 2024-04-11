
// Problem : A. Beautiful Matrix
// Contest : Codeforces Round #161 (Div. 2)
// URL : https://codeforces.com/problemset/problem/263/A
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
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++){
			int x;
			scanf("%i",&x);
			if(x==1){
				printf("%i",abs(3-i)+abs(3-j));
				return 0;	
			}		
		}
	return 0;
}