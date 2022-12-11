#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=1e6+5;
char s[N];
int sum[N],Min[N],val[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		long long res=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+(s[i]=='+'?1:-1);
			Min[i]=min(Min[i-1],sum[i]);
			val[i]=-Min[i];
			res+=1ll*i*(val[i]-val[i-1]);
		}
		printf("%lld\n",res+n);
	}
	return 0;
}