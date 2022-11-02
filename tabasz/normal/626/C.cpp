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


int main()
{
	//ios_base::sync_with_stdio(0);
	int n, m;
	scanf("%d%d", &n, &m);
	int p=1, k=3000000, mid=(p+k)/2, r=3000000;
	while(p<=k)
	{
		int a2=mid/2;
		int a3=mid/3;
		int a6=mid/6;
		if(a2>=n && a3>=m && a2+a3-a6>=n+m)
		{
			r=min(r, mid);
			k=mid-1;
		}
		else
			p=mid+1;
		mid=(p+k)/2;
	}
	printf("%d\n", r);
	return 0;
}