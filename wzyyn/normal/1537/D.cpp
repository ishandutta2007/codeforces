#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	if (n%2) puts("Bob");
	else if (n==(n&(-n))){
		int t=0;
		for (;n;n>>=1) ++t;
		puts(t&1?"Alice":"Bob");
	}
	else puts("Alice");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}