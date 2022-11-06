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

const long long mod = 1000000007;
const int maxn = 100005, maxd = 135;

int divs[maxn][maxd], top[maxn];

long long pow_mod(long long v, long long st){
	long long ans = 1, a = v;
	for(; st; st /= 2){
		if (st & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
	}
	return ans;
}

long long lss[maxn];
int a[maxn];

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, i, j, lst, mx;
	long long ans, cur, tmp, tmp1, tmp2;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++)
		lss[a[i] + 1]++;
	for(i = 1; i < maxn; i++)
		lss[i] += lss[i - 1];
	for(i = 1; i < maxn; i++){
		for(j = i; j < maxn; j+= i){
			divs[j][top[j]++] = i;
		}
	}
	ans = 1;
	mx = 0;
	for(i = 2; i < maxn; i++){
		cur = 1;
		lst = 0;
		for(j = 0; j < top[i]; j++){
			tmp = pow_mod(j, lss[divs[i][j]] - lss[lst]);
			cur = (cur * tmp) % mod;
			lst = divs[i][j];
		}
		mx = max(mx, j);
		tmp2 = pow_mod(j - 1, n - lss[lst]);
		tmp1 = pow_mod(j, n - lss[lst]);
		tmp = (tmp1 - tmp2 + mod) % mod;
		cur = (cur * tmp) % mod;
		ans = (ans + cur) % mod;
	}
	printf("%I64d", ans);
}