#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <string>

using namespace std;


int main() {
	int t;
	string s;



	cin >> t;

	while(t--) {
		cin >> s;

		int n = s.size();
		bool flag = 0;
		// cout << s << "\n";
		for(int i = n - 1; i > 0; i--) {
			int x = s[i] - '0';
			int y = s[i - 1] - '0';

			if(x + y > 9) {
				flag = 1;
				string a = to_string(x + y);
				s[i] = a[1];
				s[i - 1] = a[0];
				break;
			}
		}
		
		if(!flag) {
			int x = s[0] - '0';
			int y = s[1] - '0';

			s[0] = (x + y) + '0';
			s.erase(s.begin()+1);
		}

		cout << s << endl;
	}
}