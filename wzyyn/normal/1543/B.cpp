#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n,x,s=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		s=(s+x)%n;
	}
	cout<<1ll*s*(n-s)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}