#include<bits/stdc++.h>

using namespace std;

char s[55];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1),v=0;
	for (int i=1;i<=n;i++) v+=(s[i]=='N');
	puts(v==1?"NO":"YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}