#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n,x,y;
char s[Maxn];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	int cnt=0,len=strlen(s+1);
	for (int i=1;i<=len;i++)
		if (s[i]=='0'&&(i==1||s[i-1]=='1')) ++cnt;
	if (cnt==0) printf("%d\n",0); else printf("%lld\n",y+1LL*(cnt-1)*min(x,y));
	return 0;
}