#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,s=0,x;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		s+=x;
	}
	cout<<(s%n?1:0)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}