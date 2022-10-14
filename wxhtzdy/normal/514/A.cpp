#include <bits/stdc++.h>
using namespace std;

void inv(char& c) {
	c = (char) '9' - c + '0';
}

int main() {
	string S; cin >> S;
	int N = (int) S.size();
	for (int i = 1; i < N; i++) {
		if (S[i] >= '5') inv(S[i]);
	}
	if (S[0] >= '5' && S[0] < '9') inv(S[0]);
	cout << S;
	return 0;
}