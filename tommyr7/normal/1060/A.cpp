#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[37];
char s[1007];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int len=strlen(s+1);
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=len;i++)
		++cnt[s[i]-'0'];
	int ans=n/11;
	ans=min(ans,cnt[8]);
	printf("%d\n",ans);
	return 0;
}