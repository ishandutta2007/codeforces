#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll ta,tb;
ll a[200001],b[200002];
ll c[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> ta >> tb >> k;
	if(k>=min(n,m)){
		cout << "-1\n";
		return 0;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];a[i]+=ta;
	}
	for(int i=1; i<=m ;i++){
		cin >> b[i];
	}
	int ptr=1;
	for(int i=1; i<=k+1 ;i++){
		while(ptr<=m && b[ptr]<a[i]) ptr++;
		c[i]=ptr;
	}
	ll ans=0;
	for(int i=k+1; i>=1 ;i--){
		if(c[i]+k+1-i>m) return cout << -1 << '\n',0;
		ans=max(ans,b[c[i]+k+1-i]+tb);
	}
	cout << ans << endl;
}