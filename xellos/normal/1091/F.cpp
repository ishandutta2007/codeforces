#include <iostream>
#include <vector>
#include <set>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<cat> L(N);
	for(int i = 0; i < N; i++) cin >> L[i];
	string S;
	cin >> S;
	set<int> non_zero[2];
	int found = 0;
	cat ans = 0;
	for(int i = 0; i < N; i++) {
		if(S[i] != 'L') {
			non_zero[(S[i] == 'W') ? 0 : 1].insert(i);
			found |= 1 << ((S[i] == 'W') ? 0 : 1);
			continue;
		}
		ans += L[i];
		while(L[i]) {
			if(non_zero[0].empty() && non_zero[1].empty()) {
				if(found & 1) ans += 3 * L[i];
				else ans += 5 * L[i];
				break;
			}
			int tp = non_zero[0].empty();
			auto it = (tp == 0) ?--end(non_zero[0]) : begin(non_zero[1]);
			cat d = min(L[i], L[*it]);
			L[i] -= d;
			L[*it] -= d;
			ans += (3+2*tp) * d;
			if(L[*it] == 0) non_zero[tp].erase(it);
		}
	}
	for(auto it = begin(non_zero[1]); it != end(non_zero[1]); it++) {
		while(L[*it] > 0 && !non_zero[0].empty()) {
			auto jt = begin(non_zero[0]);
			if(*jt > *it) break;
			cat d = min(L[*it], L[*jt]);
			ans += 4 * d;
			L[*it] -= d;
			L[*jt] -= d;
			if(L[*jt] == 0) non_zero[0].erase(jt);
			else break;
		}
	}
	for(int k = 0; k < 2; k++) {
		cat l = 0;
		for(auto it = begin(non_zero[k]); it != end(non_zero[k]); it++) l += L[*it];
		ans += l * (2+k);
	}
	cout << ans << "\n";
}