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

int n, res;
int T[500005];

void go(int p, int k)
{
	//printf("%d %d\n", p, k);
	res=max(res, (k-p+2)/2);
	if((k-p)%2==0)
		for(int i=p; i<=k; i++)
			T[i]=T[p-1];
	else
	{
		int mid=(p+k)/2;
		for(int i=p; i<=mid; i++)
			T[i]=T[p-1];
		for(int i=mid+1; i<=k; i++)
			T[i]=T[k+1];
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	int tmp=0;
	for(int i=2; i<n; i++)
	{
		if(T[i-1]!=T[i] && T[i+1]!=T[i])
			tmp++;
		else
		{
			if(tmp)
				go(i-tmp, i-1);
			tmp=0;
		}
	}
	if(tmp!=0)
		go(n-tmp, n-1);
	printf("%d\n", res);
	for(int i=1; i<=n; i++)
		printf("%d ", T[i]);
	printf("\n");
	return 0;
}