#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005];
int n,ans[200005];
bool check(int x)
{
	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			if(num1<x)ans[i]=1,num1++;
			else if(num2<x)ans[i]=0,num2++;
			else return 0;
		}
		else
		{
			if(num1)num1--,ans[i]=1;
			else num2--,ans[i]=0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	check(l);
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}