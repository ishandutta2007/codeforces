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
const int N=1000050;
ll a[N],b[N];
ll pre[N],ans=9e18;
void Try(int n, ll p)
{
	for(int i=1;i<=n;i++) b[i]=a[i];
	int ptr=1;
	ll tmp=0;
	//printf("%lld\n",p);
	while(ptr<=n)
	{
		b[ptr]%=p;
		while(ptr<=n && b[ptr]==0) ptr++;
		if(ptr>n) break;
		ll fir=p/2;
		ll sec=p-fir;
		ll need=fir;
		while(need>0)
		{
			ll sub=min(need,b[ptr]);
			tmp-=sub*ptr;
			need-=sub;
			b[ptr]-=sub;
			while(ptr<=n && b[ptr]==0) ptr++;
		}
		ll mid=ptr;
		tmp+=fir*mid;
		tmp-=sec*mid;
		need=sec;
		while(need>0)
		{
			ll sub=min(need,b[ptr]);
			tmp+=sub*ptr;
			need-=sub;
			b[ptr]-=sub;
			while(ptr<=n && b[ptr]==0) ptr++;
		}
	}
	ans=min(ans,tmp);
}
int main()
{
	int n;
	ll sum=0;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),pre[i]=pre[i-1]+a[i];
	sum=pre[n];
	if(sum==1) return 0*printf("-1\n");
	for(ll i=2;(ll)i*i<=sum;i++)
	{
		if(sum%i) continue;
		while(sum%i==0) sum/=i;
		Try(n,i);
	}
	if(sum>1) Try(n,sum);
	printf("%lld\n",ans);
	return 0;
}