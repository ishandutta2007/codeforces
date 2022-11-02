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

int n, T[100];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", T+i);
	sort(T, T+n);
	unique(T, T+n);
	for(int i=0; i+2<n; i++)
	{
		if(T[i+2]==0)
			break;
		if(T[i+1]==T[i]+1 && T[i+2]==T[i+1]+1)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}