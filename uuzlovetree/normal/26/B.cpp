#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
char s[maxn];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=0,num=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')num++;
		if(s[i]==')'&&num)num--,ans+=2;
	}
	printf("%d\n",ans);
	return 0;
}