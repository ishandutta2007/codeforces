#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int t,x,top,l;
char s[3000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		scanf("%s",s+1);
		top=(int)strlen(s+1);
		l=0;
		ll len=top;
		while(l<x)
		{
			l++;
			len=(len+(len-l)*(s[l]-'1'))%MOD;
			if(top<x)
			{
				int n=top;
				for(int i=1;i<=s[l]-'1';i++)
				{
					for(int j=l+1;j<=n;j++)
					  s[++top]=s[j];
				}
			}
		}
		if(len<0)len+=MOD;
		printf("%lld\n",len);
	}
	return 0;
}