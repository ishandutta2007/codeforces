#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, T, a, b;
        cin >> n >> T >> a >> b;
        vector<pair<int, int>> qstn(n);
        int totA = 0, totB = 0;
        for (auto& i : qstn) {
            cin >> i.second;
            totB += i.second;
        }
        totA = n - totB;
        for (auto& i : qstn) {
            cin >> i.first;
		}
		sort(qstn.begin(), qstn.end());

		int sol = 0, ctA = 0, ctB = 0, i = -1;
		do {
            if (i >= 0 && i < n) {
                if (qstn[i].second) {
                    ++ctB;
                } else {
                    ++ctA;
                }
            }
            int t = (i + 1 < n ? qstn[i + 1].first - 1 : T);
            if ((long long)ctA * a + (long long)ctB * b > t) continue;
            t -= ctA * a + ctB * b;
            int xtra = min(totA - ctA, t / a);
            t -= xtra * a;
            xtra += min(totB - ctB, t / b);
            sol = max(sol, xtra + ctA + ctB);
		} while (++i < n);
		cout << sol << "\n";
	}
}