#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[300030],b[300030];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ll tot = 0,mi = 1e18,msb = 0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		a[n] = a[0];
		b[n] = b[0];
		for(int i=1;i<=n;i++){
			tot+=max(0ll,a[i]-b[i-1]);
			if(min(a[i],b[i-1])<mi){
				mi = min(a[i],b[i-1]);
			}
		}
		cout<<tot+mi<<"\n";
	}
	return 0;
}