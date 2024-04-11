#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int n, amt = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			++amt;
			if (s[i] == 'a') s[i] = 'b';
			else s[i] = 'a';
		}
	}
	cout << amt << '\n' << s;
	return 0;
}