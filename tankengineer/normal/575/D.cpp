#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

void solve()
{
	cout << 1000 + 999 << endl;
	for(int i = 1; i <= 1000; ++ i) {
		cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
	}
	for(int i = 2; i <= 1000; ++ i) {
		cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
	}

}

int main()
{
	solve();
	return 0;
}