#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector< pair<double, int> > ran;
	for(int i = N-1; i >= 0; i--) {
		double sum = A[i], best = A[i];
		int len = 1;
		while(!ran.empty()) {
			auto r = ran.back();
			sum += r.first*r.second;
			double avg = sum / (len+r.second);
			if(avg > best) break;
			else {
				best = avg, len += r.second;
				ran.pop_back();
			}
		}
		ran.push_back({best, len});
	}
	while(!ran.empty()) {
		for(int i = 0; i < ran.back().second; i++) cout << ran.back().first << "\n";
		ran.pop_back();
	}
}