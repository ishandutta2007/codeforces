#include <iostream>
#include <climits>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int n, min_difference, min_difference_index;
	char direction;
	pair<int, int> current_pos;
	map<pair<int, int>, int> points;
	vector<pair<int, int> > substrings;
	while (t--) 
	{
		cin >> n;
		
		current_pos = make_pair(0, 0);
		points[current_pos] = 1;
		
		for (int i = 0; i < n; ++i) {
			cin >> direction;
			switch (direction) {
				case 'R': ++current_pos.first;
				break;
				case 'L': --current_pos.first;
				break;
				case 'U': ++current_pos.second;
				break;
				case 'D': --current_pos.second;
				break;
			}
			if (points[current_pos]) substrings.push_back(make_pair(points[current_pos] - 1, i));
			points[current_pos] = i + 2;
		}
		
		min_difference = INT_MAX;
		min_difference_index = -1;
		for (int i = 0; i < substrings.size(); ++i) {
			if (substrings[i].second - substrings[i].first < min_difference) {
				min_difference = substrings[i].second - substrings[i].first;
				min_difference_index = i;
			}
		}
		
		if (min_difference_index != -1) cout << substrings[min_difference_index].first + 1 << ' ' << substrings[min_difference_index].second + 1;
		else cout << -1;
		cout << '\n';
		
		points.clear();
		substrings.clear();
	}
	return 0;
}