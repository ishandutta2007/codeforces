#include<bits/stdc++.h>
using namespace std;
const int max_S=1<<24|5;
int sum[max_S];
char str[6];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str);
		int res=0;
		for(int j=0;j<=2;++j)
			res|=1<<(str[j]-'a');
		++sum[res];
	}
	const int Full=(1<<24)-1;
	for(int i=0;i<24;++i)
		for(int S=0;S<=Full;++S)
		{
			if(S>>i&1)
				sum[S]+=sum[S^(1<<i)];
		}
	int ans=0;
	for(int S=0;S<=Full;++S)
		ans^=(n-sum[S])*(n-sum[S]);
	printf("%d\n",ans);
	return 0;
}