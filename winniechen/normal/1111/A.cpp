#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
char s[N],t[N];
int main()
{
	int n,m;scanf("%s%s",s+1,t+1);n=strlen(s+1),m=strlen(t+1);
	if(n!=m)return puts("No"),0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==t[i])continue;
		if((s[i]=='a'||s[i]=='u'||s[i]=='e'||s[i]=='i'||s[i]=='o')&&(t[i]=='a'||t[i]=='u'||t[i]=='e'||t[i]=='i'||t[i]=='o'))continue;
		if((s[i]!='a'&&s[i]!='u'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o')&&(t[i]!='a'&&t[i]!='u'&&t[i]!='e'&&t[i]!='i'&&t[i]!='o'))continue;
		puts("No");return 0;
	}puts("Yes");
}