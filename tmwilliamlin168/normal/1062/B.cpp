#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<int, int> mp;
	int n, a1=1, a2=0, a3=1, a4=0;
	cin >> n;
	if(n==1) {
		cout << "1 0";
		return 0;
	}
	for(int i=2; i<=n; ++i) {
		while(n%i==0) {
			++mp[i];
			n/=i;
		}
	}
	bool ne=0;
	for(auto it=mp.begin(); it!=mp.end(); ++it) {
		a1*=it->first;
		if(a2&&it->second!=a2)
			ne=1;
		a2=max(it->second, a2);
	}
	while(a2>a3) {
		a3*=2;
		++a4;
	}
	cout << a1 << " " << a4+(ne||a2!=a3);
}