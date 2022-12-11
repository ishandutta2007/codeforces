#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int my_count(string s, string t) {
	int ans = 0;
	bool flag;
	for (int i = 0; i + t.size() <= s.size(); i++) {
		flag = 1;
		for (int j = 0; j < t.size(); j++) {
			if (s[i + j] != t[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	string d = "Danil", o = "Olya", sl = "Slava", a = "Ann", n = "Nikita";
	int c;
	if (my_count(s, "Danil") + my_count(s, "Olya") + my_count(s, "Slava") + my_count(s, "Ann") + my_count(s, "Nikita") == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}