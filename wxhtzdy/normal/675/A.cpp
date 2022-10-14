#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if(c==0) {
		cout << (a==b?"YES":"NO");
		return 0;
	}
	if(c>0&&b<a) {
		cout << (a==b?"YES":"NO");
		return 0;
	}
	if(c<0&&a<b) {
		cout << (a==b?"YES":"NO");
		return 0;
	}
	cout << (a==b||(b-a)%c==0?"YES":"NO");
	return 0;		
}