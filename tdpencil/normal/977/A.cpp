#include <bits/stdc++.h>
#define REP(i, a) for(int i = 0; i < a; i++)
#define LP(x, y) for(auto x : y)
using namespace std;
void prti(int i) {
	cout << i << '\n';
}
void prts(string s) {
	cout << s << '\n';
}
int read() {
	int b; cin >> b;
	return b;
}
int main() {
	int b = read(), x = read();
	while(x--){
		if(!(b%10)) b/=10;
		else b--;
	}
	prti(b);
	return 0;
}