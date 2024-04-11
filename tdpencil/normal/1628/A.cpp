#include <bits/stdc++.h>
using namespace std;
int t, n, i;
const int mxN=2e5;

int a[mxN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	while(t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<int> suffix_mex(n);

		int mex = 0;
		vector<bool> haves(n + 1);

		for(int i = n - 1; i >= 0; i--) {
			haves[a[i]] = true;
			while(haves[mex])
				mex++;
			suffix_mex[i] = mex;
		}
		mex = 0;
		fill(haves.begin(), haves.end(), false);

		int last_seen = 0;

		vector<int> answer_array, currents;
		for(int i = 0; i < n; i++) {
			haves[a[i]] = true;
			currents.push_back(a[i]);
			while(haves[mex])
				mex++;

			if(mex == suffix_mex[last_seen]) {

				answer_array.push_back(mex);

				for(int &el : currents) {
					haves[el]=false;
				}

				currents.clear();
				mex = 0;
				last_seen = i + 1;
			}
		}
		if(last_seen != n)
			answer_array.push_back(mex);

		cout << answer_array.size() << "\n";

		for(int answer : answer_array) {
			cout << answer << " ";
		}

		cout << "\n";
	}
}