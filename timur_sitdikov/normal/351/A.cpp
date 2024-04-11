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
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 20005;
int p[MAXN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, i, j, k, top, lim, a, b, ans = 0, cur;
	cin >> n;
	top = 0;
	for(i = 0; i < 2 * n; i++){
		scanf("%d.%d", &a, &b);
		if (b){
			p[top++] = b;
		}
	}
	lim = 2 * n - top;
	ans = 2 * 1000 * n;
	for(i = 0; i <= lim; i++){
		if (lim - i > n || i > n)
			continue;
		cur = 0;
		for(j = 0; j < n - i; j++){
			cur += p[j];
		}
		for(k = 0; k < n - (lim - i); k++, j++){
			cur += p[j] - 1000;
		}
		if (abs(cur) < ans){
			ans = abs(cur);
		}
	}
	printf("%d.", ans / 1000);
	a = ans % 1000;
	printf("%03d", a);
}