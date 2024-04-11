#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int m, n, i, j;
	int step = 10000, offset = 1000000;
	cin >> n >> m;
	if (m == 3 && (n == 6 || n == 5)){
		printf("-1");
		return 0;
	}
	for(i = 0; i < m; i++){
		printf("%d %d\n", i * step, i * (i - 1) / 2);
	}
	for(i = 0; i < n - m; i++){
		printf("%d %d\n", i * step, -offset - i * (i - 1) / 2);
	}
}