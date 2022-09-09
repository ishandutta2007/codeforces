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
char s[N],tmp[N];
int pre[N],n;
void rot(int x)
{
	for(int i=x+1;i<=n;i++) tmp[i-x]=s[i];
	for(int i=1;i<=x;i++) tmp[i+n-x]=s[i];
    for(int i=1;i<=n;i++) s[i]=tmp[i];
}
void P()
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(s[i]=='('?1:-1);
	}
}
int main()
{
	scanf("%i",&n);
	scanf("%s",s+1);
	P();
	if(pre[n]!=0) return 0*printf("0\n1 1\n");
	int mn=1;
	for(int i=1;i<=n;i++) if(pre[i]<pre[mn]) mn=i;
	rot(mn);
	P();
	//printf("%i\n",mn);
	//printf("%s\n",s+1);
	vector<pair<int,int>> v,h;
	for(int i=1,j=1;i<=n;i++)
	{
		if(pre[i]==0)
		{
			v.pb({j,i});
			j=i+1;
		}
	}
	int ans=v.size();
	int L=1,R=1;
	for(auto p:v)
	{
		int l,r;
		tie(l,r)=p;
		int cnt=0;
		//printf("%i %i\n",l,r);
		for(int i=l+1,j=l+1;i<=r;i++)
		{
			if(pre[i]==1)
			{
				cnt++;
				h.pb({j,i});
				j=i+1;
			}
		}
		if(cnt+1>ans)
		{
			ans=cnt+1;
			L=l+mn;
			R=r+mn;
		}
	}
	for(auto p:h)
	{
		int l,r;
		tie(l,r)=p;
		int cnt=0;
		for(int i=l+1;i<=r;i++)
		{
			if(pre[i]==2)
			{
				cnt++;
			}
		}
		if(cnt+v.size()+1>ans)
		{
			ans=cnt+v.size()+1;
			L=l+mn;
			R=r+mn;
		}
	}
	if(L>n) L-=n;
	if(R>n) R-=n;
	printf("%i\n",ans);
	printf("%i %i\n",L,R);
	return 0;
}