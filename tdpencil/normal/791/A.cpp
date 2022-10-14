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
int main() 
{
	int bx = read(), dy = read(), count=0;
	while(bx<=dy) {
		bx*=3; dy*=2; count++;
	}
	prti(count);
	return 0;
		



}