#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
char s[max_n];
int sum[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d%s",&n,&q,s+1);
		for(int i=1;i<=n;++i)
			sum[i]=sum[i-1]+(i&1?-1:1)*(s[i]=='+'?1:-1);
		for(int i=1;i<=q;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(sum[r]-sum[l-1]==0)
				puts("0");
			else if((r-l+1)&1)
				puts("1");
			else
				puts("2");
		}
	}
    return 0;
}