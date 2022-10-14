#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int lc=0,uc=0;
	cin >> s;
	for(auto &c: s) {
		if(isupper(c)) uc++;
		else lc++;
	}
	if(lc>=uc) {
		for(auto &c: s)
			putchar(tolower(c));
	} else {
		for(auto &c: s){
			putchar(toupper(c));
		}
	}
}