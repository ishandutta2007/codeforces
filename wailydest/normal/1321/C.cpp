#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solve(string &str, int &sl, int &sr);

int main() 
{
	int n;
	string str;
	cin >> n >> str;
	int begin = 0, end = n - 1;
	solve(str, begin, end);
	cout << n - str.size() << '\n';
	return 0;
}

void solve(string &str, int &sl, int &sr) 
{
	if (sr - sl + 1 <= 1) return;
	if (sr - sl + 1 == 2) {
		if (str[sl] + 1 == str[sr]) {
			str.erase(str.begin() + sr);
			--sr;
		}
		if (str[sr] + 1 == str[sl]) {
			str.erase(str.begin() + sl);
			--sr;
		}
		return;
	}
	
	int min_index = sl;
	for (int i = sl + 1; i <= sr; ++i) if (str[min_index] > str[i]) min_index = i;
	--min_index;
	int prev_min_index = min_index;
	if (min_index - sl >= 1) solve(str, sl, min_index);
	sr -= prev_min_index - min_index;
	min_index += 2;
	if (sr - min_index >= 1) solve(str, min_index, sr);
	
	
	--min_index;
	while (min_index > 0 && str[min_index - 1] - 1 == str[min_index]) {
		--sr;
		--min_index;
		str.erase(str.begin() + min_index);
	}
	while (min_index < sr && str[min_index + 1] - 1 == str[min_index]) {
		--sr;
		str.erase(str.begin() + min_index + 1);
	}
}