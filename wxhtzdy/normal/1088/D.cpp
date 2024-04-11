#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int ask(LL a, LL b)
{
	cout << "? " << a << " " << b << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main()
{
	int st = ask(0, 0);
	if(st == 0) {
		LL a = 0, b = 0;
		rep(i, 30) {
			if(ask(1 << i, 0) == -1) a += (1 << i), b += (1 << i);
		}
		cout << "! " << a << " " << b << endl;
		return 0;
	}
	LL x = 0, y = 0;
	for(int i = 29; i >= 0; i --) {
		int idx = ask(x ^ (1 << i), y);
		int idy = ask(x, y ^ (1 << i));
		if(idx == idy) {
			if(st == 1) x += (1 << i);
			else y += (1 << i);
			st = idx;
			continue;
		}
		if(idx == -1) {
			x += (1 << i);
			y += (1 << i);
		}
	}
	cout << "! " << x << " " << y << endl;
	return 0;
}