#include<bits/stdc++.h>
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false);cin.tie(nullptr);

	int A;
	cin >> A ;
	string S;
	cin >> S;
	set<char> T;
	for(auto &s: S) {
		T.insert(tolower(s));
	}
	if(T.size()==26) cout << "YES";
	else cout << "NO";
}