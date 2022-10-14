#include <bits/stdc++.h>

using namespace std;

int main() {
 	string s;
 	cin >> s;
 	cout << (int)(s[(int)s.length() - 1] - '0') % 2;
}