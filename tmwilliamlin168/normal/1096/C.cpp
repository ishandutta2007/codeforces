#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,n,mcm,ans,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		for(ans=1; !(ans*n % 180 == 0 && ans*n/180 <= ans-2); ans++){}
		cout<<ans<<endl;
	}
}