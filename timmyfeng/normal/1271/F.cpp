#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int ma1, pr1, pe1, ma2, pr2, pe2, all, no_pe, no_pr, just_ma, no_ma, just_pr, just_pe;
		cin >> ma1 >> pr1 >> pe1 >> ma2 >> pr2 >> pe2 >> all >> no_pe >> no_pr >> just_ma >> no_ma >> just_pr >> just_pe;

		bool ok = false;
		for (int i = 0; i <= no_ma && !ok; ++i) {
			for (int j = 0; j <= no_pr && !ok; ++j) {
				for (int k = 0; k <= no_pe && !ok; ++k) {
					int a1 = ma1 - j - k;
					int b1 = pr1 - i - k;
					int c1 = pe1 - i - j;
					int a2 = ma2 - no_pr - no_pe + j + k;
					int b2 = pr2 - no_ma - no_pe + i + k;
					int c2 = pe2 - no_ma - no_pr + i + j;
					int mn1 = min({a1, b1, c1});
					int mn2 = min({a2, b2, c2});
					
					if (mn1 >= 0 && mn2 >= 0 && 
							all <= mn1 + mn2 && 
							just_ma + all <= a1 + a2 && 
							just_pr + all <= b1 + b2 && 
							just_pe + all <= c1 + c2) {
						cout << min(all, mn1) << " " << k << " " << j << " " << 
								min(just_ma, a1 - min(all, mn1)) << " " << i << " " <<
								min(just_pr, b1 - min(all, mn1)) << " " <<
								min(just_pe, c1 - min(all, mn1)) << "\n";
						ok = true;
					}
				}
			}
		}

		if (!ok) {
			cout << "-1\n";
		}
	}
}