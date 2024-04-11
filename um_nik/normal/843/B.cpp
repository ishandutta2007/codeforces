#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int B = 1000;
int CNT = 0;

int pos, curVal;
int n;
int X;

pii query(int p)
{
	CNT++;
	if (CNT == 2000) throw;
	printf("? %d\n", p);
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == -1) throw;
	return mp(x, y);
}

void answer(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
}

const int N = 50500;
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	srand(time(0));

	scanf("%d%d%d", &n, &pos, &X);	
	pii t = query(pos);
	curVal = t.first;
	if (curVal >= X) {
		answer(curVal);
		return 0;
	}
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	random_shuffle(a, a + n);
	for (int i = 0; i < min(n, B); i++) {
		int p = a[i];
		t = query(p);
		if (t.first <= X && t.first > curVal) {
			pos = p;
			curVal = t.first;
		}
	}
	while(pos != -1) {
		t = query(pos);
		if (t.first >= X) {
			answer(t.first);
			return 0;
		}
		pos = t.second;
	}
	answer(-1);

	return 0;
}