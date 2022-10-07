#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i+=2)
	{
		if(s[i]==s[i+1])
		{
			ans++;
			if(s[i]=='a')s[i]='b';
			else s[i]='a';
		}
	}
	printf("%d\n",ans);
	printf("%s\n",s+1);
	return 0;
}