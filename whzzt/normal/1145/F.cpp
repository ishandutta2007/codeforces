#include <bits/stdc++.h>

using namespace std;

string U = "AEFHIKLMNTVWXYZ";
string S;
int cnt;

int main(){
	cin >> S;
	for (char c : S) {
		bool k = false;
		for (char e : U) if (c == e) k = true;
		if (k) ++cnt;
	}
	if (cnt % S.size()) puts("NO"); else puts("YES");
}