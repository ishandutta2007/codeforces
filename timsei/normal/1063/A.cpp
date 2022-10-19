#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];

int n;

int main() {
	cin >> n;
	cin >> s;
	n = strlen(s);
	sort(s, s + n);
	cout << s << endl;
}