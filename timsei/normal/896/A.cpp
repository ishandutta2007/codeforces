#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int f[N];

const string be = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string se = "What are you doing while sending %What are you doing at the end of the world? Are you busy? Will you save us?%? Are you busy? Will you send %What are you doing at the end of the world? Are you busy? Will you save us?%?";
const int more = 218 - 75 * 2;
const string one = "What are you doing while sending %";
const string two = "%? Are you busy? Will you send %";
const string three = "%?";

char solve(int x , int y) {
	if(y > f[x]) return '.';
	if(x == 0) return be[y - 1];
//	if(x == 1) return se[y - 1];
	if(y <= one.length()) return one[y - 1];
	y -= one.length();
	if(y <= f[x - 1]) return solve(x - 1 , y);
	y -= f[x - 1];
	if(y <= two.length()) return two[y - 1];
	y -= two.length();
	if(y <= f[x - 1]) return solve(x - 1 , y);
	y -= f[x - 1];
	return three[y - 1];
}

main(void) {
	f[0] = 75; f[1] = 218;
	for(int i = 1;i <= 100000;++ i) {
		f[i] = f[i - 1] * 2 + more;
		if(f[i] > 1e18) f[i] = 1e18 + 1;
	}
	int t;
	for(cin >> t;t --;) {
		int n , k;
		cin >> n >> k;
		char now = solve(n , k);
		if(now == '%') {
			putchar('"');
		}
		else {
			putchar(now);
		}
	}
}