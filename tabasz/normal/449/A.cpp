#include<algorithm>
#include<cstdio>
#include<vector>
#include<math.h>
#include<set>
#include<queue>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

LL divide(int a, int b, int x)
{
	if(a+b-2<x) return -1;
	if(a<=x) return divide(b, 1, x-a+1);
	LL res=0;
	if(b>x) res=max(res, (LL)a*(LL)(b/(x+1)));
	res=max(res, (LL)b*(LL)(a/(x+1)));
	return res; 
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if(n<m) swap(n, m);
	cout<< divide(n, m, k) << '\n';
	//printf("%lld\n", divide(n, m, k));
	return 0;
}