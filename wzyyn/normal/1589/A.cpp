#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%lld %lld\n",1ll*x*x,-1ll*y*y);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}