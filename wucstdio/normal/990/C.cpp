#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,c1[300005],c2[300005];
char s[300005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		int c=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')num++;
			else if(num)num--;
			else c++;
		}
		if(c&&num)continue;
		if(c==0)c2[num]++;
		if(num==0)c1[c]++;
	}
	long long ans=0;
	for(int i=0;i<=300000;i++)ans+=1ll*c1[i]*c2[i];
	printf("%lld\n",ans);
	return 0;
}