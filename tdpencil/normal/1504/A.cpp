#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define vt vector
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
int main() {

	int T; scanf("%d", &T);
	while(T--) {
		string s; cin >> s;
		bool allA=true;
		trav(i, s) {
			allA&=i=='a';
		}
		
		if(allA) {
			puts("NO");
			continue;
		}
		
		int n = s.size();
		bool done=false;
		for(int i = 0; i < n && !done; i++) {
			int other = n - i - 1;
			
			if(s[i]==s[other] && s[i]!='a') {
				done=true;
				puts("YES");
				cout << s.substr(0, i) + 'a' + s.substr(i) << "\n";
			} else if(s[i] != s[other]) {
				if(s[other] != 'a' || s[i] != 'a') {
					done=true;
					puts("YES");
					cout << s.substr(0, i+1) + 'a' + s.substr(i+1) << "\n";
				}
				
			}
		}
		
		if(done) continue;
		puts("NO");
		
		
	}
}