#include <iostream>
#include <string>
using namespace std;

int solve() 
{
	string str;
	cin >> str;
	int max_distance = 1;
	int current_distance = 0;
	for (int i = 0; i < str.size(); ++i) {
		++current_distance;
		if (str[i] == 'R') {
			if (max_distance < current_distance) max_distance = current_distance;
			current_distance = 0;
		}
	}
	++current_distance;
	return current_distance > max_distance ? current_distance : max_distance;
}

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
	return 0;
}