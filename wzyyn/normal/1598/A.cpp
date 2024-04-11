#include<bits/stdc++.h>

using namespace std;

int n;
char s[2][105];
void solve(){
	scanf("%d%s%s",&n,s[0]+1,s[1]+1);
	for (int i=1;i<=n;i++)
		if (s[0][i]=='1'&&s[1][i]=='1')
			return puts("NO"),void(0);
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}