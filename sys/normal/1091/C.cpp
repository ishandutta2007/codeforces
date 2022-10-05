#include <bits/stdc++.h>
using namespace std;
int n,cnt;
long long arr[100005];
int main()
{
	scanf("%d",&n);
	int maxi=sqrt(n);
	for(int i=1;i<=maxi;i++)
	{
		if(n%i==0)
		{
			arr[++cnt]=(n-i+2)*(long long)(n/i)/2;
			if(i*i!=n) arr[++cnt]=(n-n/i+2)*(long long)i/2;
		}
	}
	sort(arr+1,arr+1+cnt);
	for(int i=1;i<=cnt;i++)
		printf("%lld ",arr[i]);
	return 0;
}