#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll a[300001],mk[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	ll sum=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> mk[i];
		sum+=a[i];
	}
	if(sum<0){
		for(int i=1; i<=n ;i++) a[i]=-a[i];
	}
	ll ans=0;
	for(int i=62; i>=0 ;i--){
		ll sum=0;
		for(int j=1; j<=n ;j++){
			if(mk[j]==(1LL<<i)) sum+=a[j];
		}
		if(sum>0) ans|=(1LL<<i);
		for(int j=1; j<=n ;j++){
			if(mk[j]&(1LL<<i)){
				mk[j]^=(1LL<<i);
				if(sum>0) a[j]=-a[j];
			}
		}
	}
	cout << ans << endl;
}