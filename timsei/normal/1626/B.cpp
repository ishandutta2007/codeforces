#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, l, ok;
char s[N];

int main() {
	for(cin >> T; T --;) {
		scanf("%s", s + 1);
		l = strlen(s + 1);
		for(int i = 1; i <= l; ++ i) s[i] -= '0';
		ok = 0;
		for(int i = 1; i < l; ++ i) {
			ok |= (s[i] + s[i + 1] >= 10);
		}
		vector <int> pos;
		for(int i = 1; i < l; ++ i) {
			if(ok) {
				if(s[i] + s[i + 1] >= 10) pos.push_back(i); 
			} else pos.push_back(i);
		}
		
		if(ok) {
			int a = pos.back();
			for(int i = 1; i < a; ++ i) {
				putchar(s[i] + '0');
			}
			printf("%d", s[a] + s[a + 1]);
			for(int i = a + 2; i <= l; ++ i) putchar(s[i] + '0');
		} else {
			int a = pos[0];
			for(int i = 1; i < a; ++ i) {
				putchar(s[i] + '0');
			}
			printf("%c", (s[a] + s[a + 1]) + '0');
			for(int i = a + 2; i <= l; ++ i) putchar(s[i] + '0');			
		}
		puts("");
	}
}