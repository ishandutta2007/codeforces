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

int n;
int T[100005], X[100005];
bool B[100005];
LL P[100005], R[100005], res;
PII L[100005];

LL getres(int ind)
{
	return P[L[ind].S]-P[L[ind].F-1];
}

void add(int ind)
{
	B[ind]=1;
	if(B[ind-1])
	{
		L[ind].F=L[ind-1].F;
		L[ind].S=ind;
		L[L[ind].F].S=ind;
	}
	if(B[ind+1])
	{
		L[L[ind+1].S].F=L[ind].F;
		L[L[ind].F].S=L[ind+1].S;
		ind=L[ind+1].S;
	}
	res=max(res, getres(ind));
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", T+i);
		P[i]=P[i-1]+T[i];
		L[i]=MP(i, i);
	}
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		X[i]=a;
	}
	for(int i=n; i>=1; i--)
	{
		//printf("%d %d %d\n", n-i, res, X[i].S);
		R[i]=res;
		add(X[i]);
	}
	for(int i=1; i<=n; i++)
		printf("%lld\n", R[i]);
	return 0;
}