#include <iostream>
#include <climits>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	int arr[100000];
	int segments_amount[100000] = {0};
	vector<pair<int, int> > segments(m);
	
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	for (int i = 0; i < m; ++i) {
		cin >> segments[i].first;
		cin >> segments[i].second;
		for (int j = segments[i].first - 1; j < segments[i].second; ++j) ++segments_amount[j];
	}
	
	int min_difference[300];
	for (int i = 0; i < n; ++i) 
		min_difference[i] = arr[i] - segments_amount[i];
	
	int max_result = INT_MIN;
	vector<int> segments_for_max;
	for (int i = 0; i < n; ++i) {
		vector<int> current_segments;
		vector<int> copy(n);
		for (int g = 0; g < n; ++g) copy[g] = arr[g];
		for (int j = 0; j < m; ++j) {
			if (segments[j].first - 1 <= i && segments[j].second - 1 >= i) {
				current_segments.push_back(j);
				for (int k = segments[j].first - 1; k < segments[j].second; ++k) --copy[k];
			}
		}
		int result = *max_element(copy.begin(), copy.end()) - min_difference[i];
		if (result > max_result) {
			max_result = result;
			segments_for_max = current_segments;
		}
	}
	
	cout << max_result << '\n';
	cout << segments_for_max.size() << '\n';
	for (int i = 0; i < segments_for_max.size(); ++i) cout << segments_for_max[i] + 1 << ' ';
	cout << '\n';
	
	return 0;
}