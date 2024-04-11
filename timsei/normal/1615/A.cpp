#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n;
char s[N];

void m() {
	cin >> n;
	long long s = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", &T), s += T;
	if(s % n == 0) puts("0");
	else puts("1");
}

int main() {
	int c;
	for(cin >> c; c --;) m();
}