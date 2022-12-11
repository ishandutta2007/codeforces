#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[3007];
bool a[30];
bool check(char x)
{
	if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return true;
	return false;
}
int main()
{
	scanf("%s",s);
	int n=strlen(s),lx=0;
	for (int i=0;i<n;i++)
	{
		if (check(s[i]))
		{
			printf("%c",s[i]);
			lx=i+1;
		} else
		{
			int t=0;
			memset(a,false,sizeof(a));
			for (int j=lx;j<=i;j++)
				a[s[j]-'a']=true;
			for (int j=0;j<26;j++)
				if (a[j]) ++t;
			if (t>1&&i-lx+1>=3) 
			{
				printf(" ");
				lx=i;
			}
			printf("%c",s[i]);
		}
	}
	printf("\n");
	return 0;
}