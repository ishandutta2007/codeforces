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

const int MAXN = 200005;

int d[MAXN], u[MAXN];

long long t, ab, acb, abc, acbc;
long long tmp_ab, tmp_acb, tmp_abc, tmp_acbc;

int check(){
	return t >= ab + tmp_ab && t >= abc + tmp_abc && t >= acbc + tmp_acbc /*&& t >= acb + tmp_acb*/;
}

void update(){
	ab += tmp_ab;
	abc += tmp_abc;
	acbc += tmp_acbc;
	//acb += tmp_acb;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, a, b, c, i, l, r, j;

	cin >> n >> t >> a >> b >> c;
	for(i = 1; i < a; i++){
		d[i] = 1;
		u[i] = 1;
	}
	d[a] = 1;
	u[a] = b;
	for(i = a + 1; i < a + c; i++){
		d[i] = u[i - 1];
		u[i] = d[i] + 1;
	}
	for(i = a + c; i <= n; i++){
		d[i] = u[i - 1];
		u[i] = d[i];
	}
	u[n] = n;
	ab = acb = abc = acbc = 0;
	for(i = 1; i <= n; i++){
		for(j = d[i]; j <= u[i]; j++){
			if (i == 1 && j == 1)
				continue;
			ab += abs(a - i) + abs(b - j);
			acb += abs(a + c - 1 - i) + abs(b - j);
			abc += abs(a - i) + abs(b + c - 1 - j);
			acbc += abs(a + c - 1 - i) + abs(b + c - 1 - j);
		}
	}
	if (ab > t || abc > t || acbc > t || acb > t){
		cout << "Impossible";
		return 0;
	}

	u[a] = b + c - 1;
	for(i = a + 1; i < a + c; i++){
		d[i] = u[i - 1];
		u[i] = d[i];
	}
	u[n] = n;

	ab = acb = abc = acbc = 0;
	for(i = 1; i <= n; i++){
		for(j = d[i]; j <= u[i]; j++){
			if (i == 1 && j == 1)
				continue;
			ab += abs(a - i) + abs(b - j);
			acb += abs(a + c - 1 - i) + abs(b - j);
			abc += abs(a - i) + abs(b + c - 1 - j);
			acbc += abs(a + c - 1 - i) + abs(b + c - 1 - j);
		}
	}

	int mid, bound;
	
	for(i = a + 1; i <= n; i++){	
		l = d[i - 1];
		r = d[i];
		bound = min(b, d[i]);	
		tmp_abc = (d[i] - l) * 2;
		if (i < a + c){
			tmp_acbc = 0;
		}
		else{
			tmp_acbc = tmp_abc;
		}
		if (l >= bound){
			tmp_ab = 0;
		}
		else{
			tmp_ab = (bound - l) * 2;
		}
		if (check()){
			update();
			u[i - 1] = d[i] = l;
			continue;
		}
		for(; l + 1 < r; ){
			mid = (l + r) >> 1;
			tmp_abc = (d[i] - mid) * 2;
			if (i < a + c){
				tmp_acbc = 0;
			}
			else{
				tmp_acbc = tmp_abc;
			}
			if (mid >= bound){
				tmp_ab = 0;
			}
			else{
				tmp_ab = (bound - mid) * 2;
			}
			if (check()){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		mid = r;
		tmp_abc = (d[i] - mid) * 2;
		if (i < a + c){
			tmp_acbc = 0;
		}
		else{
			tmp_acbc = tmp_abc;
		}
		if (mid >= bound){
			tmp_ab = 0;
		}
		else{
			tmp_ab = (bound - mid) * 2;
		}
		update();
		u[i - 1] = d[i] = mid;
	}
	//**************************************************
	for(i = 1; i <= n; i++){
		for(j = d[i]; j < u[i]; j++){
			putchar('U');
		}
		if (i != n){
			putchar('R');
		}
	}
}