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
	int n,m,q;
	scanf("%i %i",&n,&m);
	vector<string> A(n),B(m);
	for(int i=0;i<n;i++) cin>>A[i];	
	for(int i=0;i<m;i++) cin>>B[i];
	scanf("%i",&q);
	while(q--)
	{
		int y;
		scanf("%i",&y);
		y--;
		cout<<A[y%n]<<B[y%m]<<"\n";
	}	
	return 0;
}