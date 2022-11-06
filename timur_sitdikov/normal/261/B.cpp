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
#define xx real()
#define yy imag()

const int maxn = 55;

double p[maxn][maxn][2 * maxn];
int n, top, pp;
int a[maxn], a1[maxn];

void get_p(){
	int i, j, k;
	for(i = 0; i <= top; i++){
		for(j = 0; j <= i; j++){
			for(k = 0; k <= pp; k++){
				p[i][j][k] = 0.;
			}
		}
	}
	p[0][0][0] = 1.;
	for(i = 0; i < top; i++){
		for(j = 0; j <= i; j++){
			for(k = 0; k <= pp; k++){
				p[i + 1][j + 1][k + a1[i]] += p[i][j][k];
				p[i + 1][j][k] += p[i][j][k];
			}
		}
	}
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, j, k, l, sum;
	double ans = 0., koef;
	cin >> n;
	sum = 0;
	for(i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	cin >> pp;
	if (sum <= pp){
		cout << n << ".000000000000";
		return 0;
	}	
	for(l = 0; l < n; l++){
		top = 0;
		for(i = 0; i < l; i++)
			a1[top++] = a[i];
		for(i++; i < n; i++)
			a1[top++] = a[i];
		get_p();		
		koef = 1. / n;
		for(j = 0; j < n; j++){
			for(k = max(0, pp - a[l] + 1); k <= pp; k++){
				ans += koef * j * p[n - 1][j][k];
			}
			if (j < n - 1){
				koef = koef * (j + 1) / (n - j - 1);
			}
			
		}
	}
	printf("%.12lf", ans);
}