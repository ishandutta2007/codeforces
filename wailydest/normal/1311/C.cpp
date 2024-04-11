#include <iostream>
#include <algorithm> 
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	int n, m;
	string str;
	map<char, int> letters;
	int p[200002];
	while (t--) {
		cin >> n >> m;
		cin >> str;
		for (int i = 1; i <= m; ++i) cin >> p[i];
		p[0] = 0;
		p[m + 1] = n;
		sort(p + 1, p + m + 1);
		
		for (int i = 1, pressed = m + 1; i <= m + 1; ++i, --pressed) 
			for (int j = p[i - 1]; j < p[i]; ++j) letters[str[j]] += pressed;
		
		for (char ch = 'a'; ch <= 'z'; ++ch) cout << letters[ch] << ' ';
		cout << '\n';
		
		letters.clear();
	}
	
	return 0;
}