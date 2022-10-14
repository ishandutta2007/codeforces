#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll a;
	cin >> a;
	ll ans=0;
	while(a--){
		string s;
		cin >> s;
		if(s[1]=='-') ans-=1;
		else ans+=1;
	}
	cout << ans;
}