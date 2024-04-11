#include<bits/stdc++.h>
using namespace std;
int main() {
	map<string, int> mp;
	mp["monday"] = 0;
	mp["tuesday"] = 1;
	mp["wednesday"] = 2;
	mp["thursday"] = 3;
	mp["friday"] = 4;
	mp["saturday"] = 5;
	mp["sunday"] = 6;
	string a, b;
	cin >> a >> b;
	int x(mp[a]), y(mp[b]);
	y = (y - x + 7) % 7;
	printf("%s\n", y == 31 % 7 || y == 30 % 7 || y == 28 % 7 ? "YES" : "NO");
}