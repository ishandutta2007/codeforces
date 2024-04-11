#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		string S;
		cin >> N >> S;
		string ans;
		for(int i = 0; i < N; i++) if((S[i]-'0')%2)
			if((int)ans.length() < 2) ans += S[i];
		if((int)ans.length() <= 1) ans = "-1";
		cout << ans << "\n";
	}
}