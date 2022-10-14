#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,k,d,a[500050],dp[500050] = {0};

int main() {
	cin>>n>>k>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0] = 1;
	ll l = 0;
	for(int i=1;i<=n;i++){
		while((a[l+1]+d<a[i]||dp[l] == 0) && i-l>=k+1)l+=1;
		if(a[l+1]+d>=a[i] && i-l>=k){
			//cout<<i<<' '<<l<<endl;
			dp[i] = dp[l];
		}
	}
	if(dp[n]){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}