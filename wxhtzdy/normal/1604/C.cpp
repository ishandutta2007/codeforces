#include <bits/stdc++.h>
using namespace std;

int T,n,A[500005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",A+i);
		}
		int kk=1;
		long long Lc=1;
		for(int i=1;i<=n;i++)
		{
			Lc=(Lc*(i+1))/__gcd(Lc,(long long)(i+1));
			if(Lc>1e9) break;
			if(A[i]%Lc==0) kk=0;
		}
		if(kk)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}