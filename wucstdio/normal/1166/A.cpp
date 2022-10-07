#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int n,num[105],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		num[s[1]-'a'+1]++;
	}
	for(int i=1;i<=26;i++)
	{
		int len=num[i]/2;
		ans+=len*(len-1)/2;
		len=num[i]-len;
		ans+=len*(len-1)/2;
	}
	printf("%d\n",ans);
	return 0;
}