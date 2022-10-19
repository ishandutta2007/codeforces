#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

struct NODE {
	int S, id;
	friend bool operator < (NODE a, NODE b) {
		return (a.S > b.S);
	}
	void input(void) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		S = a + b + c + d;
	}
}T[N];

int main(void) {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++ i) T[i].input();
	int now = 1;
	for(int i = 2; i <= n; ++ i) if(T[i] < T[1]) ++ now;
	cout << now << endl;
}