#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[57];
int len,ans=0;
bool check(int lx,int rx)
{
	for (int i=lx;i<=rx;i++)
		if (s[i]!=s[rx+lx-i]) return true;
	return false;
}
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for (int i=1;i<=len;i++)
		for (int j=i;j<=len;j++)
			if (check(i,j)) ans=max(ans,j-i+1);
	printf("%d\n",ans);
	return 0;
}