#include <bits/stdc++.h>
using namespace std;
const int N=500050;
char s[N];
int main()
{
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	char mn='z';
	for(int i=1;i<=n;i++)
	{
		if(mn<s[i]) printf("Ann\n");
		else printf("Mike\n");
		mn=min(mn,s[i]);
	}
	return 0;
}