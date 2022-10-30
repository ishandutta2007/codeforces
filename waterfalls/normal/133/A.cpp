#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	bool found = 0;
	cin >> s;
	found|=(find(s.begin(),s.end(),'H')!=s.end());
	found|=(find(s.begin(),s.end(),'Q')!=s.end());
	found|=(find(s.begin(),s.end(),'9')!=s.end());
	printf("%s\n",found ? "YES" : "NO");

	return 0;
}