#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int n, max_interval, current_interval;
	bool was_first_A;
	char ch;
	while (t--) {
		was_first_A = false;
		max_interval = 0;
		current_interval = 0;
		cin >> n;
		while (n--) {
			cin >> ch;
			if (ch == 'A') {
				was_first_A = true;
				max_interval = max(max_interval, current_interval);
				current_interval = 0;
			}
			else 
				if (was_first_A) ++current_interval;
		}
		max_interval = max(max_interval, current_interval);
		cout << max_interval << '\n';
	}
	
	return 0;
}