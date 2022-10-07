#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans1[1005],ans2[1005],top;
char s[1005];
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	bool flag=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='('&&s[i+1]==')')
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		printf("0\n");
		return 0;
	}
	printf("1\n");
	int nowi=1,nowj=n;
	while(nowi<nowj)
	{
		while(nowi<nowj&&s[nowi]==')')nowi++;
		while(nowi<nowj&&s[nowj]=='(')nowj--;
		if(nowi>=nowj)break;
		ans1[++top]=nowi;
		ans2[top]=nowj;
		nowi++,nowj--;
	}
	printf("%d\n",top*2);
	for(int i=1;i<=top;i++)printf("%d ",ans1[i]);
	for(int i=top;i>=1;i--)printf("%d ",ans2[i]);
	printf("\n");
	return 0;
}