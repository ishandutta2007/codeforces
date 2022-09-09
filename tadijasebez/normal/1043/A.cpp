#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,sum=0,mx=0,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),sum+=x,mx=max(mx,x);
	for(i=mx;i<=1000;i++)
	{
		if(i*n-sum>sum) return 0*printf("%i\n",i);
	}
	return 0;
}