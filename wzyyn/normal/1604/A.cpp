#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,x,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		ans=max(ans,x+n-i);
	}
	printf("%d\n",ans-n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}