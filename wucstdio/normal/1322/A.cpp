#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[1000005];
int main()
{
	scanf("%d%s",&n,s+1);
	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')num1++;
		else num2++;
	}
	if(num1!=num2)
	{
		printf("-1\n");
		return 0;
	}
	int ss=0,last=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			ss++;
			if(ss==0)ans+=i-last;
			if(ss>=0)last=i;
		}
		else
		{
			ss--;
			if(ss>=0)last=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}