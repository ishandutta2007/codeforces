#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],xor_sum[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i+2<=n;++i)
	{
		if(a[i]>(a[i+1]^a[i+2]))
		{
			puts("1");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)
		xor_sum[i]=xor_sum[i-1]^a[i];
	int ans=1e9;
	for(int i=1;i<n;++i)
		for(int l=1;l<=i;++l)
			for(int r=i+1;r<=n;++r)
			{
				if((xor_sum[i]^xor_sum[l-1])>(xor_sum[r]^xor_sum[i]))
					ans=min(ans,(r-l+1)-2);
			}
	if(ans==1e9)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}