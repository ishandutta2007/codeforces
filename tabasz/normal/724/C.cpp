#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const int mid=500000;

int n, m, k;
LL t, R[100005];
PII T[100005];
vector<PII> V[1000005];

int getind(int x, int y)
{
	int qwe=min(x, y), i=0;
	x-=qwe;
	y-=qwe;
	if(x>0)
		i=-x;
	if(y>0)
		i=y;
	return mid+i;
}

void push(int x, int y, int ind)
{
	int qwe=min(x, y);
	int pos=getind(x, y);
	V[pos].PB(MP(ind, qwe));
}

void go(int x, int y, LL time)
{
	if(time>t)
		return;
	int pos=getind(x, y);
	for(int i=0; i<(int)V[pos].size(); i++)
		if(time+V[pos][i].S<=t && R[V[pos][i].F]==-1)
			R[V[pos][i].F]=time+V[pos][i].S;
	int add=min(2*n-x, 2*m-y);
	x+=add;
	y+=add;
	if(x%n==0 && y%m==0)
		return;
	x%=(2*n);
	y%=(2*m);
	go(x, y, time+add);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	t=((LL)n*m)/__gcd(n, m);
	for(int i=1; i<=k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		R[i]=-1;
		T[i]=MP(a, b);
		push(a, b, i);
		push(a, 2*m-b, i);
		push(2*n-a, b, i);
		push(2*n-a, 2*m-b, i);
	}
	go(0, 0, 0);
	for(int i=1; i<=k; i++)
		printf("%lld\n", R[i]);
	return 0;
}