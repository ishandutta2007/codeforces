#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

char s[5000]; 

int main() {
	scanf( "%s", s ); 
	int n = strlen(s); 
	vector<char> a; a.clear(); 
	int l = 0; 
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			a.clear(); 
			l = 0; 
		}
		else {
			l++; 
			bool flag = false; 
			for (auto c : a) flag |= (s[i] == c); 
			if (!flag) a.pb(s[i]); 
			if (l >= 3 && (int)a.size() >= 2) {
				printf( " " ); 
				a.clear(); a.pb(s[i]); 
				l = 1; 
			}
		}
		printf( "%c", s[i] ); 
	} 
	puts( "" ); 
	return 0;
}