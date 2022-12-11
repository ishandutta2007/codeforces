#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool check=true;
int n,k;
int a[30],b[30];
bool vis1[1000007],vis2[1000007];
char s[1000007];
int main()
{
	n=read(),k=read();
	scanf("%s",s+1);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++)
	{
		b[s[i]-'A']=i;
		if (a[s[i]-'A']==0) a[s[i]-'A']=i;
	}
	memset(vis1,false,sizeof(vis1));
	memset(vis2,false,sizeof(vis2));
	for (int i=0;i<26;i++)
		vis1[a[i]]=true,vis2[b[i]]=true;
	for (int i=1;i<=n;i++)
	{
		if (vis1[i]) --k;
		if (k<0) check=false;
		if (vis2[i]) ++k;
	}
	if (!check) printf("YES\n"); else printf("NO\n");
	return 0;
}