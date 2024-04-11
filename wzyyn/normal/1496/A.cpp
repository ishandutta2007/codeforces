#include<bits/stdc++.h>
using namespace std;

char s[105];
int n,k;
void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int p=1;
	for (;p*2<n&&s[p]==s[n-p+1];++p);
	puts(p>k?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}