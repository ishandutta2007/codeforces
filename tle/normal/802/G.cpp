# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
// # include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int M = 5e5 + 10;
const int mod = 1e9+7;

# define RG register
# define ST static

string s;

int t;
char str[] = {0, 'h', 'e', 'i', 'd', 'i'};

int main() {
	cin >> s;
	int len = s.length();
	t = 1;
	for (int i=0; i<len; ++i) {
		if(t <= 5 && s[i] == str[t]) {
			++t; continue;
		}
	}
	if(t == 6) puts("YES");
	else puts("NO");
	return 0;
}