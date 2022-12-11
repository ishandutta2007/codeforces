#include <bits/stdc++.h>
using namespace std;
char s[107];
int main()
{
	scanf("%s",s);
	int n=strlen(s),now=0;
	while (now<n&&s[now]=='0') ++now;
	int cnt=0;
	for (int i=now;i<n;i++)
		if (s[i]=='0') ++cnt;
	if (cnt>=6) printf("yes\n"); else printf("no\n");
	return 0;
}