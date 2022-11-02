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

int n, q;
int T[300005], A[300005], M[300005];
LL res;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", T+i);
		A[T[i]]=i;
	}
	for(int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a=A[a];
		b=A[b];
		if(a>b)
			swap(a, b);
		M[b]=max(M[b], a);
	}
	int tmp=0;
	for(int i=1; i<=n; i++)
	{
		tmp=max(tmp, M[i]);
		res+=i-tmp;
	}
	printf("%lld\n", res);
	return 0;
}