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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, MX = 500000;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(begin(A), end(A));
	vector<int> cnt(MX+1, 0), cnt_ps(MX+1, 0);
	for(int i = 0; i < N; i++) cnt[A[i]]++;
	for(int i = 0; i <= MX; i++) cnt_ps[i] = (i ? cnt_ps[i-1] : 0) + cnt[i];
	cat ans = 0;
	for(int y = 2; y <= MX; y++) {
		cat cnt_y = 0;
		for(int i = 1; i <= MX/y; i++)
			cnt_y += 1LL * (cnt_ps[min(MX, y*i+y-1)] - cnt_ps[y*i-1]) * i;
		if(cnt_y < 2) continue;
		int min_x = min(1LL*y, cnt_y-2), max_x = min(MX+1LL, cnt_y+1);
		while(max_x-min_x > 1) {
			int x = (min_x + max_x) / 2;
			if(2*(x/y)+x > cnt_y) {
				max_x = x;
				continue;
			}
			if(2*x <= MX) {
				int cnt2_r = 0; // ky+r >= 2x, r >= (2x)%y
				for(int i = (2*x)/y; i <= MX/y; i++)
					cnt2_r += cnt_ps[min(MX, y*i+y-1)] - cnt_ps[min(MX, max(0, y*i+(2*x)%y-1))];
				if(cnt2_r >= 1 && x+(2*x)/y <= cnt_y) {
					min_x = x;
					continue;
				}
				if(cnt_ps[MX] > cnt_ps[2*x-1] && x+(2*x+y-1)/y <= cnt_y) {
					min_x = x;
					continue;
				}
			}
			int cnt_r = 0; // ky+r >= x, r >= x%y
			for(int i = x/y; i <= MX/y; i++)
				cnt_r += cnt_ps[min(MX, y*i+y-1)] - cnt_ps[min(MX, max(0, y*i+x%y-1))];
			if(cnt_r >= 2) {
				min_x = x;
				continue;
			}
			if(cnt_ps[MX] >= 2+cnt_ps[x-1] && x+2*((x+y-1)/y)-cnt_r <= cnt_y) {
				min_x = x;
				continue;
			}
			max_x = x;
		}
		// cout << y << " " << min_x << "\n";
		if(min_x >= 2) ans = max(ans, 1LL * min_x * y);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing