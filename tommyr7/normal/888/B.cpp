#include <bits/stdc++.h>
using namespace std;
int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
int n;
char s[107];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='L') ++cnt1;
		if (s[i]=='R') ++cnt2;
		if (s[i]=='U') ++cnt3;
		if (s[i]=='D') ++cnt4;
	}
	printf("%d\n",2*min(cnt1,cnt2)+2*min(cnt3,cnt4));
	return 0;
}