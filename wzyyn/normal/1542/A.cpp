#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,x,s0=0,s1=0;
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++){
		scanf("%d",&x);
		x&1?++s1:++s0;
	}
	puts(s1==s0?"Yes":"No");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}