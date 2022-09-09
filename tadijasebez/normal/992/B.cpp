#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll gcd(ll x, ll y){ return x?gcd(y%x,x):y;}
int main()
{
	ll a,b,x,y,l,r,i;
	scanf("%lld %lld %lld %lld",&l,&r,&x,&y);
	int sol=0;
	if(y%x) return printf("0\n"),0;
	y/=x;
	for(i=1;i*i<=y;i++)
	{
		if(y%i) continue;
		a=i;
		b=y/i;
		if(gcd(a,b)==1)
		{
			if(a*x>=l && a*x<=r)
			{
				if(b*x>=l && b*x<=r)
				{
					sol++;
					if(a!=b) sol++;
				}
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}