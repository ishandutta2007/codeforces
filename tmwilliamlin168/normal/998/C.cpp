#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a;
	ll x, y;
	string s;
	cin >> n >> x >> y >> s;
	a=n;
	for(int i=0; i<n; ++i)
		if(s[i]=='1'||i&&s[i]=='0'&&s[i-1]=='0')
			--a;
//	cout << a << endl;
	if(a==0)
		cout << 0;
	else
		cout << y+(a-1)*min(x, y);
}