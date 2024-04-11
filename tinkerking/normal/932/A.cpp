#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[1010];

int main()
{
	scanf("%s",s);
	int len = strlen(s);
	for (int i=0;i<len;i++)printf("%c",s[i]);
	for (int i=len-1;i>=0;i--)printf("%c",s[i]);
	return 0;
}