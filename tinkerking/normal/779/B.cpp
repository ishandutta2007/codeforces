#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[110];
bool del[110];
int K,len,M;

int getnum()
{
	int tmp = 0;
	for (int i=1;i<=len;i++)
	if (!del[i])
		tmp = tmp*10+s[i]-'0';
	return tmp;
}

int main()
{
	scanf("%s",s+1);
	scanf("%d",&K);
	M = 1;
	for (int i=1;i<=K;i++)M*=10;
	len = strlen(s+1);
	memset(del,false,sizeof(del));
	int ans = 0, now = len;
	while(getnum()%M!=0)
	{
		if (s[now]!='0') 
		{
			del[now] = true;
			ans++;
		}	
		now--;
	}
	if (getnum()==0) ans = len-1;
	printf("%d\n",ans);
}