#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[100005];
int n;
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	ll ans=0;
	for(int i=0;i<26;i++)
	for(int j=0;j<26;j++)
	{
		ll f=0,g=0;
		for(int x=1;x<=n;x++)
		{
			if(s[x]==j+'a')g+=f;
			if(s[x]==i+'a')f++;
		}
		ans=max(ans,max(f,g));
	}
	printf("%lld\n",ans);
	return 0;
}