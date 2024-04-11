#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int solve(string& s) {
	size_t npos = string::npos;
	size_t lb = s.find('[');
	size_t rb = s.rfind(']');

	if(lb == npos || rb == npos)
		return -1;

	size_t lk = s.find(':', lb);
	size_t rk = s.rfind(':', rb);

	if(lk == npos || rk == npos || lk >= rk)
		return -1;

	return 4 + count(&s[lk], &s[rk], '|');
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s;
	cout << solve(s);
}