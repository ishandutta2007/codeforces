#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S, N;
	cin >> S >> N;
	static int occ[10];
	for(int i = 0; i < (int)S.length(); i++) occ[S[i]-'0']++;
	for(int i = 0; i < (int)N.length(); i++) occ[N[i]-'0']--;
	string ans;
	int L = N.length();
	for(int K = max(1, (int)S.length()-8); K <= (int)S.length(); K++) {
		int x = K, D = S.length();
		bool ok = true;
		while(x) {
			occ[x%10]--;
			D--;
			if(occ[x%10] < 0) ok = false;
			x /= 10;
		}
		if(ok && D == K) {
			string cur;
			if(K == (int)N.length()) {
				if(N[0] != '0' || N == "0") cur = N;
			}
			else {
				if(N[0] == '0') {
					int m = 1;
					while(m < 10 && occ[m] == 0) m++;
					if(m == 10) cur = (N == "0" && K == L) ? "0" : "";
					else {
						occ[m]--;
						cur += (char)('0'+m);
						for(int i = 0; i < occ[0]; i++) cur += '0';
						cur += N;
						for(int i = 1; i < 10; i++) for(int j = 0; j < occ[i]; j++) cur += char('0'+i);
						occ[m]++;
					}
				}
				else {
					string lt, gt, eq;
					for(int i = 0; i < N[0]-'0'; i++) for(int j = 0; j < occ[i]; j++) lt += char('0'+i);
					for(int j = 0; j < occ[N[0]-'0']; j++) eq += N[0];
					for(int i = N[0]-'0'+1; i < 10; i++) for(int j = 0; j < occ[i]; j++) gt += char('0'+i);
					if(occ[0] == 0) cur = lt + min(eq + N, N + eq) + gt;
					else if((int)lt.length() != occ[0]) {
						reverse(begin(lt), begin(lt)+occ[0]+1);
						cur = lt + min(eq + N, N + eq) + gt;
					}
					else if(eq.length() == 0) cur = N + lt + gt;
					else {
						string cur1 = min(eq + N, N + eq) + lt + gt;
						string cur2 = N + lt + eq + gt;
						lt = eq.substr(0, 1) + lt;
						eq = eq.substr(0, eq.length()-1);
						string cur3 = lt + min(eq + N, N + eq) + gt;
						cur = min(cur1, min(cur2, cur3));
					}
				}
			}
			if(ans == "" || ans.length() > cur.length()) ans = cur;
			if(ans.length() == cur.length()) ans = min(ans, cur);
		}
		x = K;
		ok = true;
		while(x) {
			occ[x%10]++;
			x /= 10;
		}
	}
	cout << ans << "\n";
}