#include <iostream>
#include <string>
using namespace std;
int n, a, b;
string s;
int main() {
	cin >> n >> a >> b;
	cin >> s;
	cout << (s[a - 1] != s[b - 1]) << endl;
	return 0;
}