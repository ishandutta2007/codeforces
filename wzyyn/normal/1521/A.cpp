#include<bits/stdc++.h>
using namespace std;


void solve(){
	int A,B;
	scanf("%d%d",&A,&B);
	if (B==1) puts("NO");
	else printf("YES\n%lld %lld %lld\n",1ll*A,1ll*A*B,1ll*A*(B+1));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}