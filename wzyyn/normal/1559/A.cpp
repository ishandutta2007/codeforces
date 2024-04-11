#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	int ans=(1<<30)-1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans&=x;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}