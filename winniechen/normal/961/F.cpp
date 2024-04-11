#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1000005
#define ll long long
const int B1 = 131;
const int p1 = 998244353;
const int B2 = 13131;
const int p2 = 1000000007;
int b1[N],h1[N],b2[N],h2[N],n,ans[N];char s[N];
int get_h1(int l,int r){return ((h1[r]-(ll)h1[l]*b1[r-l])%p1+p1)%p1;}
int get_h2(int l,int r){return ((h2[r]-(ll)h2[l]*b2[r-l])%p2+p2)%p2;}
bool check(int l,int r,int L,int R)
{
	return get_h1(l-1,r)==get_h1(L-1,R)&&get_h2(l-1,r)==get_h2(L-1,R);
}
int main()
{
	scanf("%d%s",&n,s+1);b1[0]=1,b2[0]=1;
	for(int i=1;i<=n;i++)
		h1[i]=((ll)h1[i-1]*B1+s[i])%p1,
		h2[i]=((ll)h2[i-1]*B2+s[i])%p2,
		b1[i]=(ll)b1[i-1]*B1%p1,b2[i]=(ll)b2[i-1]*B2%p2;
	for(int i=n+1>>1,now=-1;i;i--)
	{
		int l=i,r=n-i+1;ans[i]=-1;
		if(l==r)continue;
		for(now+=2;~now&&!check(i,i+now-1,r-now+1,r);now-=2);
		ans[i]=now;
	}
	for(int i=1;i<=n+1>>1;i++)printf("%d\n",ans[i]);
}