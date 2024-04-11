#include <bits/stdc++.h>
using namespace std;
int nums[1000005],ans[1000005],n,tot;
bool flag=false,tag;
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
		nums[i]=getchar()-'0';
	getchar(); 
	for(int i=1;i<=n;i++)
		ans[i]=getchar()-'0';
	for(int i=2;i<=n;i++)
	{
		if(nums[i]!=ans[i]&&nums[i-1]!=ans[i-1]&&nums[i]!=nums[i-1]){flag=true;if(i==n) tag=true;tot++;i++;}
		if(!flag&&nums[i-1]!=ans[i-1]) tot++;
		flag=false;
	}
	if(!tag&&nums[n]!=ans[n]) tot++;
	printf("%d",tot);
	return 0;
}