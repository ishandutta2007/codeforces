#include <bits/stdc++.h>
using namespace std;
int n,cnt[30],flag;
char s[100010];
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%d %s",&n,s+1);
	for (int i=1;i<=n;i++)
		cnt[s[i]-'a'+1]++;
	for (int i=1;i<=26;i++)
		if (cnt[i]>1) flag=1;
	if (flag||n==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}