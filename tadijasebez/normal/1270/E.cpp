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
const int N=100050;
int x[N],y[N],z[N],c[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i %i",&x[i],&y[i]),z[i]=x[i]+y[i];
	while(1)
	{
		for(int i=1;i<=n;i++) z[i]=x[i]+y[i],c[i]=(z[i]%2+2)%2;
		vector<int> A;
		for(int i=1;i<=n;i++) if(c[i]==0) A.pb(i);
		if(A.size()>0 && A.size()<n)
		{
			printf("%i\n",A.size());
			for(int i:A) printf("%i ",i);
			printf("\n");
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			tie(x[i],y[i])=mp(x[i]-y[i],x[i]+y[i]);
			x[i]=floor((ldb)x[i]/2);
			y[i]=floor((ldb)y[i]/2);
		}
	}
	return 0;
}