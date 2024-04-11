#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll a;
	cin >> a;
	while(a--){
		string s;
		cin >> s;
		if(s.size()>10) {
			cout << s[0] << s.size()-2 << s[s.size()-1] << '\n';
		} else {
			cout << s << "\n"; 
		}
	}
}