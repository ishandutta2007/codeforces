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
int T[1005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	sort(T+1, T+n+1);
	int tmp=n;
	for(int i=1; i<tmp; i++)
	{
		printf("%d %d ", T[i], T[tmp]);
		tmp--;
	}
	if(n%2)
		printf("%d", T[tmp]);
	printf("\n");
	return 0;
}