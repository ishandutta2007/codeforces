#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const char heart[] = "<3";
const int L = 100005;
char buf[L], b[L];

int main() {
	string a;	
	int n;
	scanf("%d", &n);
	a += heart;
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		a += buf;
		a += heart;
	}
	scanf("%s", b);
	int i = 0, j = 0, l = strlen(b);
	while (i < a.size() && j < l) {
		if (a[i] == b[j]) {
			++i, ++j;
		} else {
			++j;
		}
	}
	puts(i == a.size() ? "yes" : "no");
	return 0;
}