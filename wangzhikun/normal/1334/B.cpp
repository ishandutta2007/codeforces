#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100010],x;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		ll csu = 0,ans = 0;
		for(int i=1;i<=n;i++){
			csu+=a[i];
			if(csu>=x*i)ans = i;
		}
		cout<<ans<<endl;
	}
	return 0;
}