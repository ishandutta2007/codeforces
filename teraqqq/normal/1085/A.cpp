#include <iostream>
#include <string>

using namespace std;

string s, t;

int main() {
	cin >> t;
	s = string(t.size(), ' ');
	size_t a = (t.size()-1)/2;
	for(size_t i = 0; i <= a; ++i)
		s[2*i] = t[a-i];
	for(size_t i = 0; i+1+a < t.size(); ++i)
		s[2*i+1] = t[a+1+i];
	cout << s;
}