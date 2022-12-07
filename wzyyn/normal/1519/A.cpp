#include<bits/stdc++.h>
using namespace std;

void solve(){
	int r,b,d;
	scanf("%d%d%d",&r,&b,&d);
	if (r>1ll*b*(d+1)) puts("NO");
	else if (b>1ll*r*(d+1)) puts("NO");
	else puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}