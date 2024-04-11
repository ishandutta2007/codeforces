#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char ch[120000];
int n,i,num[50],s[120000];
long long ans;
int main()
{
	while(~scanf("%s",ch))
	{
		n=strlen(ch);
		for(i=0;i<n;i++)
		{
			if(ch[i]>='0'&&ch[i]<='9')
			{
				s[i]=ch[i]-'0'+26;
			}
			else
			{
				s[i]=ch[i]-'a';
			}
		}
		ans=0;
		memset(num,0,sizeof(num));
		for(i=0;i<n;i++)
		{
			ans+=(long long)num[s[i]];
			num[s[i]]++;
		}
		ans*=2;ans+=(long long)(n);
		printf("%lld\n",ans);
	}
}