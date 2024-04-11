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
#define PII pair<int, int>

int n, k, e, o, d, s;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a%2) o++;
		else e++;
	}
        if(k==n)
{
if(o%2==0) printf("Daenerys\n");
else printf("Stannis\n");
return 0;
}
	s=(n-k+1)/2;
	d=(n-k)/2;
	if(s>=min(e, o))
	{
		if(e<o && k%2)
		{
			printf("Stannis\n");
			return 0;
		}
		if(e==o)
		{
			printf("Stannis\n");
			return 0;
		}
	}
	if(d>=min(e, o))
	{
		if(e<o && k%2==0)
		{
			printf("Daenerys\n");
			return 0;
		}
		if(e>o)
		{
			printf("Daenerys\n");
			return 0;
		}
		if(e==o)
		{
			printf("Daenerys\n");
			return 0;
		}
	}
	if((n-k)%2) printf("Stannis\n");
	else printf("Daenerys\n");
	return 0;
}