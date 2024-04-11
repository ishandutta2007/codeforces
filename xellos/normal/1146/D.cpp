#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int gcd(int a, int b) {
	if(a > b) swap(a, b);
	return (a == 0) ? b : gcd(b%a, a);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int M, A, B;
	cin >> M >> A >> B;
	vector<int> min_x(A+B, A+B);
	min_x[0] = 0;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	q.push({0, 0});
	while(!q.empty()) {
		pair<int, int> p = q.top();
		q.pop();
		if(min_x[p.ss] != p.ff) continue;
		if(p.ss >= B && min_x[p.ss-B] > p.ff) {
			min_x[p.ss-B] = p.ff;
			q.push({p.ff, p.ss-B});
		}
		if(p.ss+A < A+B && min_x[p.ss+A] > max(p.ff, p.ss+A)) {
			min_x[p.ss+A] = max(p.ff, p.ss+A);
			q.push({max(p.ff, p.ss+A), p.ss+A});
		}
	}
	vector<int> cnt_new(A+B, 0);
	for(int i = 0; i < min(M+1, A+B); i++) if(min_x[i] < A+B) cnt_new[min_x[i]]++;
	cat ans = 0, cur = 0;
	for(int x = 0; x < min(M+1, A+B); x++) {
		cur += cnt_new[x];
		ans += cur;
	}
	int g = gcd(A, B);
	if(M >= A+B) {
		cat m1 = (A+B)/g, m2 = M/g;
		cat sum = m2 * (m2+1) / 2 - m1 * (m1+1) / 2;
		ans += g * sum;
		for(int x = M-M%g; x <= M; x++) ans += m2+1;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing