#include <bits/stdc++.h>
using namespace std;
char s[100007];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int cnt0=0,cnt1=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='n') ++cnt1; else if (s[i]=='o') ++cnt0;
	cnt0-=cnt1;
	for (int i=1;i<=cnt1;i++)
		printf("%d ",1);
	for (int i=1;i<=cnt0;i++)
		printf("%d ",0);
	printf("\n");
	return 0;
}