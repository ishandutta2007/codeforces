#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll af;
	cin >> af;

	vector<int> f;
	vector<int> s;
	ll ans=0;
	for(int i=0; i<af; i++) {
		int a, b;
		cin >> a >> b;
		f.emplace_back(a);
		s.emplace_back(b);
	}
	for(int i =0; i < af; i++){
		for(int j=0; j < af; j++){
			if(i==j) continue;
			if(f[i] == s[j]) ans++;
		}
	}
	cout << ans;
}