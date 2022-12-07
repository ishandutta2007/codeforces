#include<bits/stdc++.h>

using namespace std;

int n;
char s[100005];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int k=1;
	if (n>=2&&s[2]<s[1])
		for (;k+1<=n&&s[k]>=s[k+1];++k);
	for (int i=1;i<=k;i++) putchar(s[i]);
	for (int i=k;i>=1;i--) putchar(s[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}