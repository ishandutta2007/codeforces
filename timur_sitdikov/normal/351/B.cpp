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

const int MAXN = 3005;

int p[MAXN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ans, n, i, j, inv;
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> p[i];
	}
	inv = 0;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if (p[i] > p[j]){
				inv++;
			}
		}
	}
	if (inv & 1){
		ans = 2 * inv - 1;
	}
	else {
		ans = 2 * inv;
	}
	cout << ans << ".000000000";
}