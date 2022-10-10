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

void query(vector<cat> numbers, cat & mi, cat & mx, int & q) {
	cout << numbers.size();
	ALL_THE(numbers, it) cout << " " << *it;
	cout << endl;
	int ans;
	cin >> ans;
	if(ans < 0) exit(0);
	if((int)numbers.size() > ans) mx = numbers[ans]-1;
	if(ans > 0) mi = numbers[ans-1]+1;
	q--;
}

void over10000(cat & mi, cat & mx, int & q) {
	int K = 10000;
	// K+1-nary search
	while(q > 0) {
		vector<cat> numbers;
		cat dist = (mx-mi+1)/(K+1)+1;
		cat cur = mi-1+dist;
		while((int)numbers.size() < K && cur <= mx) {
			numbers.push_back(cur);
			cur += dist;
		}
		query(numbers, mi, mx, q);
	}
	assert(0);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	cat ask[] = {204761410474LL, 2046, 6, 2, 1};
	cat mi = 1, mx = 10004205361450474LL;
	int q = 5;
	for(int k = 0; k < 5; k++) {
		cout << "1 " << ask[k] << endl;
		q--;
		int ans;
		cin >> ans;
		if(ans < 0) return 0;
		if(ans == 0) {
			mx = ask[k]-1;
			continue;
		}
		else {
			mi = ask[k]+1;
			break;
		}
	}
	if(mi >= 10000) over10000(mi, mx, q); // q == 4
	if(q == 3) {
		cat dist = 10001*10001, cur = mx+1;
		vector<cat> numbers;
		for(int i = 0; i < mi; i++) {
			cur -= dist;
			numbers.push_back(cur);
		}
		reverse(begin(numbers), end(numbers));
		query(numbers, mi, mx, q);
	}
	if(mi >= 10000) over10000(mi, mx, q);
	if(q == 2) {
		vector<cat> numbers;
		if(mx > 10000) {
			cat dist = 10001, cur = mx+1-dist;
			while((int)numbers.size() < mi && cur >= mi) {
				numbers.push_back(cur);
				cur -= dist;
			}
			numbers.pop_back();
			numbers.push_back((2047*2+1)*2);
			numbers.push_back(2047*2);
			reverse(begin(numbers), end(numbers));
		}
		else {
			cat cur = 2*mi;
			while((int)numbers.size() < mi && cur <= mx) {
				numbers.push_back(cur);
				cur = (cur+1)*2;
			}
		}
		query(numbers, mi, mx, q);
	}
	if(mi >= 10000) over10000(mi, mx, q);
	// q == 1
	assert(mx-mi+1 <= min(mi, 10000LL));
	vector<cat> numbers;
	for(cat i = mi; i <= mx; i++) numbers.push_back(i);
	query(numbers, mi, mx, q);
	return 0;
}

// look at my code
// my code is amazing