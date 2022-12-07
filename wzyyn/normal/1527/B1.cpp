#include<bits/stdc++.h>
using namespace std;

int n;
char s[1005];
void solve(){
	scanf("%d%s",&n,s+1);
	int l=1,r=n,p1=0,p2=0;
	for (;l<r;++l,--r)
		if (s[l]=='0') ++p1;
	if (l==r&&s[l]=='0') ++p2;
	if (!p2)
		puts("BOB");
	else
		puts(!p1?"BOB":"ALICE");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}