#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int inf=2e9+7;
int main()
{
	int t;scanf("%i",&t);
	while(t--)
	{
		int n,x,y,k;
		scanf("%i %i %i %i",&n,&x,&y,&k);
		int dif=abs(x-y);
		int sol=inf;
		if(dif%k==0) sol=min(sol,dif/k);
		dif=abs(y-1);
		if(dif%k==0) sol=min(sol,(x+k-2)/k+dif/k);
		dif=abs(y-n);
		if(dif%k==0) sol=min(sol,(n-x+k-1)/k+dif/k);
		if(sol==inf) sol=-1;
		printf("%i\n",sol);
	}
	return 0;
}