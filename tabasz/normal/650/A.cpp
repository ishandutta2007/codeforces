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
vector<PII> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
	}
	LL res=0;
	int prev=-1, tmp=0;
	sort(V.begin(), V.end());
	for(int i=0; i<n; i++)
	{
		if(V[i].F!=prev)
		{
			//printf(" %d\n", tmp);
			res+=((LL)tmp*(LL)(tmp-1))/2;
			tmp=0;
			prev=V[i].F;
		}
		tmp++;
	}
	res+=((LL)tmp*(LL)(tmp-1))/2;
	//printf(" %d\n", tmp);
	for(int i=0; i<n; i++)
		swap(V[i].F, V[i].S);
	sort(V.begin(), V.end());
	prev=-1;
	tmp=0;
	PII pr=MP(-1, -1);
	int tmp2=0;
	for(int i=0; i<n; i++)
	{
		if(V[i].F!=prev)
		{
			res+=((LL)tmp*(LL)(tmp-1))/2;
			//printf(" %d\n", tmp);
			tmp=0;
			prev=V[i].F;
		}
		tmp++;
		if(V[i]!=pr)
		{
			res-=((LL)tmp2*(LL)(tmp2-1))/2;
			//printf("     %d\n", tmp2);
			tmp2=0;
			pr=V[i];
		}
		tmp2++;
	}
	res+=((LL)tmp*(LL)(tmp-1))/2;
	//printf(" %d\n", tmp);
	res-=((LL)tmp2*(LL)(tmp2-1))/2;
	//printf("     %d\n", tmp2);
	printf("%lld\n", res);
	return 0;
}