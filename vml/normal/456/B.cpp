//#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <bitset>

using namespace std;

const int maxn = (int) 1e5 + 100;
int v[maxn];

int main() { 

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

int pos = 0;
char c;

while (scanf("%c", &c) != EOF) {
	if (!('0' <= c && c <= '9')) {
		break;
	}
v[pos] = c - '0';
pos++;
}

int summ = 1;
int ans = 0;

if (pos == 1) {
ans += v[pos - 1];
} else {
ans = v[pos - 2] * 10 + v[pos - 1];
}

//cout << ans << endl;

if (ans % 4 == 1) {
summ = summ + 2 + 3 + 4;
} else if (ans % 4 == 2) {
summ = summ + 4 + 4 + 1;
} else if (ans % 4 == 3) {
summ = summ + 3 + 2 + 4;
} else {
summ = summ + 1 + 1 + 1;
}

cout << summ % 5;

return 0;
}