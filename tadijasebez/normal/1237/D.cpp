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
const int N=200050;
const int inf=1e9+7;
int a[N],S[N],c,x[N],y[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),a[i+n]=a[i];
	for(int i=n*2;i>=1;i--)
	{
		while(c && a[S[c]]>=a[i]) c--;
		int top=c,bot=1,ans=inf,mid;
		while(top>=bot)
		{
			mid=top+bot>>1;
			//if(i==1) printf("%i %i %i %i %i\n",i,mid,S[mid],a[S[mid]],a[i]);
			if(a[S[mid]]*2<a[i]) ans=S[mid],bot=mid+1;
			else top=mid-1;
		}
		x[i]=ans;
		S[++c]=i;
	}
	multiset<int> st;
	for(int i=1;i<=n;i++) st.insert(n+x[i]);//,printf("%i ",x[i]);
	//printf("\n");
	for(int i=n;i>=1;i--)
	{
		st.erase(st.find(n+x[i]));
		st.insert(x[i]);
		y[i]=*st.begin()-i;
	}
	for(int i=1;i<=n;i++)
	{
		if(y[i]>inf/2) printf("-1 ");
		else printf("%i ",y[i]);
	}
	return 0;
}