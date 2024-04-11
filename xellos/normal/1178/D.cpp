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
	int N;
	cin >> N;
	if(N == 3) {
		cout << "3\n";
		for(int i = 0; i < 3; i++) cout << i+1 << " " << ((i+1)%3)+1 << "\n";
		return 0;
	}
	if(N == 5) {
		cout << "5\n";
		for(int i = 0; i < 5; i++) cout << i+1 << " " << ((i+1)%5)+1 << "\n";
		return 0;
	}
	if(N == 6) {
		cout << "7\n";
		for(int i = 0; i < 6; i++) cout << i+1 << " " << ((i+1)%6)+1 << "\n";
		cout << "1 4\n";
		return 0;
	}
	vector<int> is_prime(2*N+1, 0);
	for(int i = 2; i <= 2*N; i++) {
		is_prime[i] = 1;
		for(int j = 2; j < i; j++) if(i%j == 0) {
			is_prime[i] = 0;
			break;
		}
	}
	int Q = N/4;
	if(N%4 == 1) Q = (N-5)/4;
	if(N%4 == 2) Q = (N-6)/4;
	int add_e = 0;
	for(int i = N; i <= N+2*Q; i++) if(is_prime[i]) {
		add_e = i-N;
		break;
	}
	cout << N+add_e << "\n";
	for(int k = 0; k < Q; k++) {
		cout << N << " " << N-1 << "\n" << N-1 << " " << N-2 << "\n";
		cout << N << " " << N-3 << "\n" << N-3 << " " << N-2 << "\n";
		if(add_e) {
			cout << N << " " << N-2 << "\n";
			add_e--;
		}
		if(add_e) {
			cout << N-1 << " " << N-3 << "\n";
			add_e--;
		}
		N -= 4;
	}
	if(N == 3)
		for(int i = 0; i < 3; i++) cout << i+1 << " " << ((i+1)%3)+1 << "\n";
	if(N == 5)
		for(int i = 0; i < 5; i++) cout << i+1 << " " << ((i+1)%5)+1 << "\n";
	if(N == 6) {
		for(int i = 0; i < 3; i++) cout << i+1 << " " << ((i+1)%3)+1 << "\n";
		for(int i = 0; i < 3; i++) cout << i+4 << " " << ((i+1)%3)+4 << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing