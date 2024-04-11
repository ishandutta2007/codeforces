#include <bits/stdc++.h>
using namespace std;
#define int long long
int q;
signed main(){
	cin>>q;
	while(q--){
		int k,n,b,a;
		cin>>k>>n>>a>>b;
		if(k<=n*b){
			puts("-1");
			continue;
		}
		cout<<min(n,(k-(n*b)-1)/(a-b))<<endl;
	}
	return 0;
}