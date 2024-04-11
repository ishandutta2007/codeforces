#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int x;cin >> x;
		int s=0;
		for(;(1<<s)<=x;s++);
		int w=(1<<s)-1;
		int ans=w;
		if(w==x){
			ans=1;
			for(int i=2;i<=sqrt(x);i++)
				if(x%i==0){ans=max(ans,x/i);}
		}
		cout<<ans<<endl;
	}
	return 0;
}