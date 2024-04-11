#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
string str;
int x, ans;
void work1() {
	--x;
	int now = 4;
	for (int i = 1; i <= 366; ++i) {
		if (now == x) ++ans;
		now = (now + 1) % 7;
	}	
}
void work2() {
	if (x <= 29) ans = 12;
	else if (x == 30) ans = 11;
	else ans = 7;
}
int main() {
	cin >> x;
	cin >> str;
	cin >> str;
	if (str == "week") work1();
	else work2();
	printf("%d\n", ans);
}