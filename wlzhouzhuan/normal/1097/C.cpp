#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define rep2(i, l, r) for (RE int i = l; i >= r; i--)

string a;
char tmp[500005];
int s[300005];
int n;

int ABS(int k) {
	return k < 0 ? -k : k;
}

int main() {
	scanf("%d\n", &n);
	int N = n; n = 0;
	rep(i, 1, N) {
		cin >> a;
		int l = a.size();
		
		int tp = 0;
		rep(j, 0, l - 1) {
			if (a[j] == '(') tmp[tp++] = a[j];
			else if (a[j] == ')') {
				if (tmp[tp - 1] == '(') tp--;
				else tmp[tp++] = a[j];
			}
		}
/*		
		printf("%d %d \n", i, tp);
		rep(j, 0, tp - 1) {
			putchar(tmp[j]);
		}
		putchar('\n');
*/
		bool ok = 1;
		rep(j, 0, tp - 2) {
			if (tmp[j] != tmp[j + 1]) {
				ok = 0;
				break;
			}
		}
		if (!ok) continue;

//		printf("add it\n");
		n++;
		rep(j, 0, tp - 1) {
			if (tmp[j] == '(') s[n]++;
			else if (tmp[j] == ')') s[n]--; 
		}
	}
	sort(s + 1, s + n + 1);
	
	int x = 1, y = n;
	int ans = 0;

/*
	rep(i, 1, n) {
		printf("%d ", s[i]);
	}
	printf("\n");
*/

	while (x < y) {
//		printf("x: %d y: %d\n", x, y);
		if (ABS(s[x]) < ABS(s[y])) y--;
		else if (ABS(s[x]) > ABS(s[y])) x++;
		else if (s[x] + s[y] == 0) x++, y--, ans++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}