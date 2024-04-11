#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	s2 = s1;
	for (int i = s1.length() - 1; i >= 0; --i) {
		s2.append(1, s1[i]);
	}
	cout << s2 << endl;
	return 0;
}