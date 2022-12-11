#include<bits/stdc++.h>
using namespace std;
const int max_len=1e6+5;
char s[max_len];
int sum[max_len];
inline bool query(int L,int R)
{
	return sum[R]>sum[L-1];
}
bool ok[max_len];
long long res1[max_len],res2[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d%s",&n,&m,s+1);
		int len=n*m;
		for(int i=1;i<=len;++i)
		{
			sum[i]=sum[i-1]+(s[i]^'0');
			res1[i]=res2[i]=0;
		}
		for(int i=1;i<=len;++i)
			res1[i]+=query(max(i-m+1,1),i);
		for(int i=m+1;i<=len;++i)
			res1[i]+=res1[i-m];
		for(int i=1;i<=len;++i)
		{
			ok[i]=(s[i]^'0')|(i>m?ok[i-m]:0);
			if(ok[i])
				++res2[i],--res2[min(i+m,len+1)];
		}
		for(int i=1;i<=len;++i)
			res2[i]+=res2[i-1];
		for(int i=1;i<=n*m;++i)
			printf("%lld%c",res1[i]+res2[i],i<n*m?' ':'\n');
	}
	return 0;
}