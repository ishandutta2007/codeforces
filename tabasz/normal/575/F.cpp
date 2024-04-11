#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, p, k;
LL res=0;

int main()
{
	ios_base::sync_with_stdio(0);
	//scanf("%d%d", &n, &p);
	cin>> n >> p;
	k=p;
	for(int i=1; i<=n; i++)
	{
		int a, b;
		cin>> a >> b;
		if(a<=k && b>=p)
		{
			p=max(p, a);
			k=min(k, b);
		}
		else
		{
			if(a>k)
			{
				res+=(a-k);
				p=k;
				k=a;
			}
			else
			{
				res+=(p-b);
				k=p;
				p=b;
			}
		}
	}
	cout<< res << '\n';
	return 0;
}