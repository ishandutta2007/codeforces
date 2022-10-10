#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,t;
	cin >> s >> t;
	int x =0, x2 =0;
	for(int i =0; i < s.length(); i++) x +=(s[i] == '+')?1:-1;
	int u =0;
	for(int i =0; i < t.length(); i++) {
		if(t[i] == '+') x2++;
		if(t[i] == '-') x2--;
		if(t[i] == '?') u++;}
	double ans =1;
	for(int i =0; i <= u; i++) if(x == x2+i-(u-i)) {
		for(int j =0; j < i; j++) ans *=1.0*(u-j)/(j+1);
		for(int j =0; j < u; j++) ans *=0.5;
		cout << fixed << setprecision(10) << ans << "\n";
		return 0;}
	cout << "0\n";}