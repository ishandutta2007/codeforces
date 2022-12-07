#include<bits/stdc++.h>

using namespace std;


void solve(){
	long long a,c;
	int b,d;
	scanf("%lld%d%lld%d",&a,&b,&c,&d);
	if (b+6<d) putchar('<');
	else if (d+6<b) putchar('>');
	else{
		for (;b>d;a*=10,--b);
		for (;d>b;c*=10,--d);
		if (a==c) putchar('=');
		else putchar(a<c?'<':'>');
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}