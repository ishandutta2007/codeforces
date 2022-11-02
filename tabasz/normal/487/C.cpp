#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

vector<int> V;
bool T[100005];
bool A[100005];

void sito()
{
	for(int i=2; i<=100000; i++)
	{
		if(A[i]==0)
		{
			V.PB(i);
			int x=i+i;
			while(x<=100000)
			{
				A[x]=1;
				x+=i;
			}
		}
	}
}

LL pot(LL x, LL p, LL mod)
{
	if(p==1) return x;
	LL y=pot(x, p/2, mod);
	y=(y*y)%mod;
	if(p%2) y=(y*x)%mod;
	return y;
}

int main()
{
	sito();
	int n;
	scanf("%d", &n);
	if(n==4)
	{
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	if(n==1)
	{
		printf("YES\n1\n");
		return 0;
	}
	bool b=0;
	for(int i=0; i<V.size(); i++) if(V[i]==n) b=1;
	if(!b)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n1\n");
	for(int j=2; j<n; j++)
	{
		int x=((LL)j*pot((LL)(j-1), (LL)(n-2), (LL)n))%(LL)n;
		printf("%d\n", x);
	}
	printf("%d\n", n);
	return 0;
}