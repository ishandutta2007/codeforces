#include<bits/stdc++.h>
using namespace std;

void solve(){
	char s[105];
	scanf("%s",s+1);
	int n=strlen(s+1);
	int p=1;
	for (int i=2;i<=n;i++)
		if (s[i]<s[p])
			p=i;
	putchar(s[p]);
	putchar(' ');
	for (int i=1;i<=n;i++)
		if (i!=p)
			putchar(s[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}