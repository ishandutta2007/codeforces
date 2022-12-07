#include<bits/stdc++.h>
using namespace std;

map<int,long long> mp;
void solve(){
	int n;
	scanf("%d",&n);
	mp.clear();
	long long ans=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans+=1ll*(n-i+1)*mp[x];
		mp[x]+=i;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}