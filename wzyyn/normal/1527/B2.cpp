#include<bits/stdc++.h>
using namespace std;

int n;
char s[1005];
void solve(){
	scanf("%d%s",&n,s+1);
	int l=1,r=n,p1=0,p2=0,p3=0,delta;
	for (;l<r;++l,--r)
		if (s[l]=='0'&&s[r]=='0') ++p1;
		else if (s[l]^s[r]) ++p2;
	if (l==r&&s[l]=='0') ++p3;
	if (!p3) delta=(!p1?0:2);
	else delta=(!p1?1:-1);
	if (p2&&-delta-(p2-1)+1<0) puts("ALICE");
	else if (delta-p2>0) puts("BOB");
	else if (delta-p2==0) puts("DRAW");
	else puts("ALICE");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}