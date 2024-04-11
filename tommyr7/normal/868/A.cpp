#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[2];
char a[107][2];
int main()
{
	scanf("%s",s);
	int n=read();
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]);
	bool check=false;
	for (int i=1;i<=n;i++)
	{
		if (a[i][0]==s[0]&&a[i][1]==s[1]) check=true;
		if (a[i][1]==s[0]&&a[i][0]==s[1]) check=true;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][1]==s[0]&&a[j][0]==s[1]) check=true;
	if (check) printf("YES\n"); else printf("NO\n");
	return 0;
}