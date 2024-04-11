#include<bits/stdc++.h>
using namespace std;
void ans(int a, int b) {
	printf("2 %d %d\n", a, b);
	fflush(stdout);
}
bool debug = 0;
int p1 = 1, p2 = 10;
bool ask(int a, int b) {
	printf("1 %d %d\n", a, b);
	fflush(stdout);
	if(debug) {
		return min(abs(a - p1), abs(a - p2)) <= min(abs(b - p1), abs(b - p2));
	}else {
		string s;
		cin >> s;
		return s == "TAK";
	}
}
int bs(int le, int ri) {
	while(le != ri) {
		int mid((le + ri) / 2);
		if(ask(mid, mid + 1)) {
			ri = mid;
		}else {
			le = mid + 1;
		}
	}
	return le;
}
int main() {
	int n, k;
	if(debug) {
		n = 10; k = 2;
	}else {
		scanf("%d%d", &n, &k);
	}
	int a(bs(1, n));
	int b(a == 1 ? -1 : bs(1, a - 1));
	if(b != -1 && ask(b, a)) {
		ans(b, a);
	}else {
		ans(bs(a + 1, n), a);
	}
}