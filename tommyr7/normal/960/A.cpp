#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
char s[Maxn];
int cnt1=0,cnt2=0,cnt3=0;
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	bool check=true;
	for (int i=1;i<n;i++)
		if (s[i]>s[i+1]) check=false;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='a') ++cnt1;
		if (s[i]=='b') ++cnt2;
		if (s[i]=='c') ++cnt3;
	}
	if (cnt1!=cnt3&&cnt2!=cnt3) check=false;
	if (cnt1==0||cnt2==0) check=false;
	if (check) printf("YES\n"); else printf("NO\n");
	return 0;
}