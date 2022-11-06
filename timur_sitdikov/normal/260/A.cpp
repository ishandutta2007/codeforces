#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

string s;

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, n, i;
	cin >> a >> b >> n;
	for(i = 0; i < 10; i++){
		if (!((10 * a + i) % b))
			break;
	}
	if (i == 10){
		printf("-1");
		return 0;
	}
	a = 10 * a + i;
	cout << a;
	for(i = 1; i < n; i++)
		putchar('0');
}