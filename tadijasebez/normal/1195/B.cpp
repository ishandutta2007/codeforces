#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=0,sum=0;sum-k<=n-i;i++,sum+=i)
	{
		if(n-i==sum-k)
		{
			printf("%i\n",sum-k);
			return 0;
		}
	}
	return 0;
}