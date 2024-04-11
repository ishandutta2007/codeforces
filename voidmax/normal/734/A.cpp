#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;

const int MAXN = 1e5;

int n;
int cnt[2];
string s;

int main() {
	//freopen("input.in", "r", stdin);
	cin >> n >> s;
	for (char i: s) {
		++cnt[i == 'A'];
	}
	if (cnt[1] > cnt[0]) {
		cout << "Anton" << endl;
	} else if (cnt[0] > cnt[1]) {
		cout << "Danik" << endl;
	} else {
		cout << "Friendship" << endl;
	}
}