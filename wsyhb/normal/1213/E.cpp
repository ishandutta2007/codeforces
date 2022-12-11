#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
char s[5],t[5];
int main()
{
	int n;
	scanf("%d%s%s",&n,s,t);
	printf("YES\n");
	if((s[0]!='a'||s[1]!='b')&&(s[0]!='b'||s[1]!='c')&&(s[0]!='c'||s[1]!='a')&&(t[0]!='a'||t[1]!='b')&&(t[0]!='b'||t[1]!='c')&&(t[0]!='c'||t[1]!='a'))
	{
		for(int i=1;i<=n;i++) printf("abc");
		return 0;
	}
	if((s[0]!='a'||s[1]!='c')&&(s[0]!='c'||s[1]!='b')&&(s[0]!='b'||s[1]!='a')&&(t[0]!='a'||t[1]!='c')&&(t[0]!='c'||t[1]!='b')&&(t[0]!='b'||t[1]!='a'))
	{
		for(int i=1;i<=n;i++) printf("acb");
		return 0;
	}
	if(((s[0]=='a'&&s[1]=='b')||(t[0]=='a'&&t[1]=='b'))&&((s[0]=='a'&&s[1]=='c')||(t[0]=='a'&&t[1]=='c')))
	{
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("a");
		return 0;
	}
	if(((s[0]=='a'&&s[1]=='b')||(t[0]=='a'&&t[1]=='b'))&&((s[0]=='c'&&s[1]=='b')||(t[0]=='c'&&t[1]=='b')))
	{
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("a");
		return 0;
	}
	if(((s[0]=='a'&&s[1]=='b')||(t[0]=='a'&&t[1]=='b'))&&((s[0]=='b'&&s[1]=='a')||(t[0]=='b'&&t[1]=='a')))
	{
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("a");
		return 0;
	}
	if(((s[0]=='b'&&s[1]=='c')||(t[0]=='b'&&t[1]=='c'))&&((s[0]=='a'&&s[1]=='c')||(t[0]=='a'&&t[1]=='c')))
	{
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("a");
		return 0;
	}
	if(((s[0]=='b'&&s[1]=='c')||(t[0]=='b'&&t[1]=='c'))&&((s[0]=='c'&&s[1]=='b')||(t[0]=='c'&&t[1]=='b')))
	{
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("a");
		for(int i=1;i<=n;i++) printf("c");
		return 0;
	}
	if(((s[0]=='b'&&s[1]=='c')||(t[0]=='b'&&t[1]=='c'))&&((s[0]=='b'&&s[1]=='a')||(t[0]=='b'&&t[1]=='a')))
	{
		for(int i=1;i<=n;i++) printf("a");
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("b");
		return 0;
	}
	if(((s[0]=='c'&&s[1]=='a')||(t[0]=='c'&&t[1]=='a'))&&((s[0]=='a'&&s[1]=='c')||(t[0]=='a'&&t[1]=='c')))
	{
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("a");
		return 0;
	}
	if(((s[0]=='c'&&s[1]=='a')||(t[0]=='c'&&t[1]=='a'))&&((s[0]=='c'&&s[1]=='b')||(t[0]=='c'&&t[1]=='b')))
	{
		for(int i=1;i<=n;i++) printf("b");
		for(int i=1;i<=n;i++) printf("a");
		for(int i=1;i<=n;i++) printf("c");
		return 0;
	}
	if(((s[0]=='c'&&s[1]=='a')||(t[0]=='c'&&t[1]=='a'))&&((s[0]=='b'&&s[1]=='a')||(t[0]=='b'&&t[1]=='a')))
	{
		for(int i=1;i<=n;i++) printf("a");
		for(int i=1;i<=n;i++) printf("c");
		for(int i=1;i<=n;i++) printf("b");
		return 0;
	}
	return 0;
}