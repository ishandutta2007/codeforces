#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[300005];
int n,len[300005];
ll ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(len,0x3f,sizeof(len));
	for(int i=2;i<n;i++)
	{
		int x=1000000000;
		for(int j=1;i-j>=1;j++)
		{
			x=min(x,len[i-j]);
			if(x<=i+j)break;
			if(s[i+j]==s[i]&&s[i-j]==s[i])
			{
				len[i-j]=min(len[i-j],i+j);
				break;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		len[i]=min(len[i],len[i+1]);
		ans+=len[i]>n?0:n-len[i]+1;
	}
	printf("%I64d\n",ans);
	return 0;
}