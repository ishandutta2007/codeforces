#include<bits/stdc++.h>

using namespace std;

char s[55];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	sort(s+1,s+n+1);
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}