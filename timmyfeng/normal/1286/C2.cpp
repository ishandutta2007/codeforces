#include <bits/stdc++.h> 
using namespace std;

#define all(x) (x).begin(), (x).end()

const int AL = 26;
const int MX = 100 + 1;

int cnt[AL][MX];

bool cmp_size(const string& a, const string& b) {
	return a.size() < b.size();
}

vector<string> qry(int l, int r) {
	int len = r - l + 1;
	vector<string> res(len * (len + 1) / 2);
	cout << "? " << l << ' ' << r << endl;
	for (auto& i : res) {
		cin >> i;
		sort(all(i));
	}
	sort(all(res));
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n <= 3) {
		string ans = "";
		for (int i = 0; i < n; ++i) {
			ans += qry(i + 1, i + 1)[0];
		}
		cout << "! " << ans << endl;
		return 0;
	}

	vector<string> qry1 = qry(1, (n + 1) / 2);
	vector<string> qry2 = qry(2, (n + 1) / 2);
	vector<string> pre;
	set_symmetric_difference(all(qry1), all(qry2), back_inserter(pre));
	sort(all(pre), cmp_size);

	string ans_pre = pre[0];
	for (int i = 1; i < int(pre.size()); ++i) {
		set_symmetric_difference(all(pre[i]), all(pre[i - 1]), back_inserter(ans_pre));
	}

	vector<string> qry3 = qry(1, n);
	for (auto& i : qry3) {
		for (auto j : i) {
			++cnt[j - 'a'][i.size()];
		}
	}

	string ans_suf = "";
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < i; ++j) {
			cnt[ans_pre[j] - 'a'][i + 2] -= j + 1;
			cnt[ans_suf[j] - 'a'][i + 2] -= j + 1;
		}
		cnt[ans_pre[i] - 'a'][i + 2] -= i + 1;

		for (int j = 0; j < AL; ++j) {
			if (cnt[j][i + 2] % (i + 2)) {
				ans_suf += j + 'a';
			}
		}
	}
	reverse(all(ans_suf));

	cout << "! " << ans_pre << ans_suf << endl;
}