#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[500005];
int n,top,num[500005],ans;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		int left=0;
		top=0;
		for(int i=1;i<=len;i++)
		{
			if(s[i]==')')top--;
			else top++;
			if(top<0)left=min(left,top);
		}
		if(left!=0&&top>left)continue;
		if(left)
		{
			if(num[-left]>0)ans++;
			num[-left]--;
		}
		else if(top==0)num[0]++;
		else
		{
			if(num[top]<0)ans++;
			num[top]++;
		}
	}
	printf("%d\n",ans+num[0]/2);
	return 0;
}