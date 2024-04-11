#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		char ch = s[i];
		if (v.size() == 0 || v.back() != ch) {
			v.push_back(ch);
		} else {
			v.pop_back();
		}
	}
	puts(v.size() ? "No" : "Yes");
	return 0;
}