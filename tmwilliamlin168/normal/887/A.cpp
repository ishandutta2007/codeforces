#include <bits/stdc++.h>
using namespace std;

int m, cnt;

int main() {
    string s;
    cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '1')
			m = 1;
		else
			if (m) cnt++;
	}
	cout << (cnt >= 6 ? "yes" : "no"); 	
}