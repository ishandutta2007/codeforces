#include<bits/stdc++.h>
using namespace std;

void solve(){
	int S=0,n,x;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		S+=x;
	}
	if (S==n) puts("0");
	else if (S<n) puts("1");
	else printf("%d\n",S-n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}