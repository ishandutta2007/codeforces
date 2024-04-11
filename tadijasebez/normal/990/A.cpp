#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}

int main()
{
	ll n,m,a,b;
	scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
	ll k=n%m;
	ll sol=min(k*b,(m-k)*a);
	printf("%lld\n",sol);
	return 0;
}