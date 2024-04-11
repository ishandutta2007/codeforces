
// Problem : D. Minimax Problem
// Contest : Educational Codeforces Round 80 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1288/problem/D
// Memory Limit : 512.000000 MB 
// Time Limit : 5000.000000 milisec 
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
const int N=300050;
const int M=8;
int a[N][M];
int id[1<<M];
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			scanf("%i",&a[i][j]);
	int top=1e9+7,bot=0,mid,ans=0,a=2,b=1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		for(int mask=0;mask<1<<m;mask++) id[mask]=0;
		for(int i=1;i<=n;i++)
		{
			int my=0;
			for(int j=0;j<m;j++) if(::a[i][j]>=mid) my|=1<<j;
			id[my]=i;
		}
		for(int i=M-1;~i;i--) 
			for(int mask=0;mask<1<<m;mask++)
				if(!(mask>>i&1))
					if(!id[mask]) id[mask]=id[mask^(1<<i)];
		bool ok=0;
		int all=(1<<m)-1;
		for(int mask=0;mask<1<<m;mask++)
		{
			if(id[mask] && id[all^mask])
			{
				ok=1;
				a=id[mask];
				b=id[all^mask];
				ans=mid;
				break;
			}
		}
		/*if(id[all])
		{
			ok=1;
			a=id[all];
			if(a==1) b=2;
			else b=a-1;
			ans=mid;
		}*/
		if(ok) bot=mid+1;
		else top=mid-1;
	}
	printf("%i %i\n",a,b);
	//printf("%i\n",ans);
	return 0;
}