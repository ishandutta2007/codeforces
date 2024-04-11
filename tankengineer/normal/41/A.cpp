#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	reverse(t.begin(), t.end());
	puts(s == t ? "YES" : "NO");
	return 0;
}