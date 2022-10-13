#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_GOODS = 5000;
constexpr long long INF = 1e18;

int initial[MAX_GOODS + 1];
int discounted[MAX_GOODS + 1];
vector<long long> dp[MAX_GOODS + 1][2];
vector<int> child[MAX_GOODS + 1];

vector<long long> total_min(vector<long long> a, vector<long long> b) {
	vector<long long> combined(a.size() + b.size() - 1, INF);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			combined[i + j] = min(combined[i + j], a[i] + b[j]);
		}
	}
	return combined;
}

void process(int g) {
	dp[g][0] = {0, initial[g]};
	/*
	 * we have INF for the first element because 0 would mess up merging
	 * if it WAS 0, then that would mean we didn't buy this one
	 * yet the algo would still think all the children are eligible for coupons
	 */
	dp[g][1] = {INF, discounted[g]};
	for (int t : child[g]) {
		process(t);
		dp[g][0] = total_min(dp[g][0],dp[t][0]);
		dp[g][1] = total_min(dp[g][1],dp[t][1]);
	}
	for (int i = 0; i < dp[g][1].size(); i++) {
		dp[g][1][i] = min(dp[g][1][i], dp[g][0][i]);
	}
}

int main() {
	int good_num;
	int budget;
	cin >> good_num >> budget;
	for (int i = 1; i <= good_num; i++) {
		cin >> initial[i] >> discounted[i];
		discounted[i] = initial[i] - discounted[i];
		if (i > 1) {
			int prereq;
			cin >> prereq;
			child[prereq].push_back(i);
		}
	}

	process(1);
	for (int i = good_num; i >= 0; i--) {
		if (dp[1][1][i] <= budget) {
			cout << i << endl;
			break;
		}
	}
}