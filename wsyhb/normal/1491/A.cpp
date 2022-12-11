#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],cnt[2];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		++cnt[a[i]];
	}
	while(q--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1)
		{
			if(a[x]==0)
				--cnt[0],++cnt[1];
			else
				--cnt[1],++cnt[0];
			a[x]^=1;
		}
		else
		{
			if(cnt[1]>=x)
				puts("1");
			else
				puts("0");
		}
	}
    return 0;
}