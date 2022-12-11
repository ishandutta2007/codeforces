#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN=200000+10;
int n;
ll ans,last,cur,k;
ll a[MAXN];
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	for(int i=1;i<=n;i++)
	{
		last+=cur;
		cur+=a[i];
		if(cur>k)
		{
			int temp=cur/k;
			if(last>temp*k) ++temp;
			ans+=temp;
			last=0;
			cur=max(0ll,cur-temp*k);
		}
		else if(last)
		{
			cur=last=0;
			++ans;
		}
	}
	printf("%I64d",ans+(cur ? 1 : 0));
	return 0;
}