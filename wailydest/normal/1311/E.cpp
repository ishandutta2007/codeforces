#include <iostream>
#include <vector>
using namespace std;

int max2pow(int n) 
{
	int result = 2, i;
	for (i = 0; result <= n; ++i, result <<= 1);
	return i;
}

void solve() 
{
	int n, d;
	cin >> n >> d;
	
	if (d > n * (n - 1) / 2 || d < (1 << max2pow(n + 1)) * (max2pow(n + 1) - 2) + 2 + (max2pow(n + 1) * (n - (1 << max2pow(n + 1)) + 1))) {
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	
	vector<int> level(n, 1);
	
	int lastlevel = n - 2, currentlevel = n - 1, fillinglevel = 1;
	for (int sum = n * (n - 1) / 2; sum > d; --sum) {
		if (currentlevel - 1 == fillinglevel && level[fillinglevel] == (1 << fillinglevel)) {
			++fillinglevel;
			currentlevel = lastlevel;
			--lastlevel;
		}
		--level[currentlevel];
		--currentlevel;
		++level[currentlevel];
		if (currentlevel == fillinglevel) {
			currentlevel = lastlevel;
			--lastlevel;
		}
	}
	
	int current_level = 1;
	int element = 2;
	vector<int> v1;
	vector<int> v2;
	vector<int> *prev_level = &v1;
	vector<int> *next_level = &v2;
	
	prev_level->push_back(1);
	
	while (current_level < n && level[current_level] > 0) {
		for (int i = 0; i < level[current_level]; ++i) {
			cout << prev_level->at(i / 2) << ' ';
			next_level->push_back(element);
			++element;
		}
		
		++current_level;
		prev_level->clear();
		swap(prev_level, next_level);
	}
	
	cout << '\n';
}

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}