#include<bits/stdc++.h>
using namespace std;
int ask(string s) {
	cout << "? " << s << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
int main() {
	int n;
	scanf("%d", &n);
	string s(n, '0');
	int c = ask(s);
	s[0] = '1';
	int a0;
	int d = ask(s);
	int pos1 = -1, pos0 = -1;
	int zo = 0;
	if(d < c) {
		pos1 = 0;
		zo = 1;
	}else {
		pos0 = 0;
	}
	if(zo == 1) {
		a0 = ask(string(n, '1'));
	}else {
		a0 = c;
	}
	int le(0), ri(n - 2);
	while(le != ri) {
		string s;
		int mid((le + ri + 1) / 2);
		for(int i(0); i <= mid; i++)
			s.push_back('1' ^ zo);
		for(int i(mid + 1); i < n; i++)
			s.push_back('0' ^ zo);
		if(ask(s) == a0 + mid + 1) {
			le = mid;
		}else {
			ri = mid - 1;
		}
	}
	if(pos1 == -1) pos1 = le + 1;
	else pos0 = le + 1;
	printf("! %d %d\n", 1 + pos0, 1 + pos1);
	fflush(stdout);
}