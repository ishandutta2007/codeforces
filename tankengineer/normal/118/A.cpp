#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int main() {
	string s; 
	cin >> s;
	string ans;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') continue;
		ans = ans + '.' + s[i];
	}
	cout << ans;
	return 0;
}