#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
string s, r;

int main() {
	cin >> n >> s;
	r.reserve(n);
	for(int i = 0, j = 0; j < n; j += ++i)
		r.push_back(s[j]);

	cout << r;
}