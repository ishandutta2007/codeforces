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
		int i = 0;
		if(s[i] == 'O') {
			ans+=8;
		}
		if(s[i] == 'D') {

			ans+=12;
		}
		if(s[i] == 'I') {
			ans+=20;
		}
		if(s[i] == 'C') {
			ans+=6;
		}
		if(s[i] == 'T') {
			ans+=4;
		}
	}
	cout << ans;
}