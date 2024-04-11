#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string S, C;
		cin >> S >> C;
		int N = S.length();
		int occ[26];
		for(int i = 0; i < 26; i++) occ[i] = 0;
		for(int i = 0; i < N; i++) occ[S[i]-'A']++;
		for(int i = 0; i < N; i++) {
			occ[S[i]-'A']--;
			bool ok = false;
			for(int j = 0; j < S[i]-'A'; j++) if(occ[j]) ok = true;
			if(!ok) continue;
			for(int j = 0; j < S[i]-'A'; j++) if(occ[j]) {
				for(int k = N-1; k > i; k--) if(S[k] == 'A'+j) {
					swap(S[k], S[i]);
					break;
				}
				break;
			}
			break;
		}
		cout << ((S < C) ? S : "---") << "\n";
	}
}