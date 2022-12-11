#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
char s[max_n];
int sum[max_n];
int main()
{
	int n,q;
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+(s[i]-'a'+1);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}