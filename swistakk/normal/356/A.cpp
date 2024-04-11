#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define uint long long int
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

const int N = 1001 * 1001;

const int M = 1 << 19;

int drz[2 * M + 5];
int win[N];

int add(int a, int b, int w) {
	a += M - 1;
	b += M - 1;
	drz[a] = min(drz[a], w);
	drz[b] = min(drz[b], w);
	while (a / 2 != b / 2) {
		if (a % 2 == 0) {
			drz[a + 1] = min(drz[a + 1], w);
		}
		if (b % 2 == 1) {
			drz[b - 1] = min(drz[b - 1], w);
		}
		a /= 2;
		b /= 2;
	}
}

int ans(int a) {
	int mini = N;
	a += M - 1;
	while (a) {
		mini = min(mini, drz[a]);
		a /= 2;
	}
	if (mini == N) {
		return 0;
	} else {
		return win[mini];
	}
}

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin>>n>>m;
	
	for (int i = 1; i <= 2 * M; i++) {
		drz[i] = N;
	}
	
	for (int i = 1; i <= m; i++) {
		int l, r, x;
		cin>>l>>r>>x;
		win[i] = x;
		if (l != x) {
			add(l, x - 1, i);
		}
		if (r != x) {
			add(x + 1, r, i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout<<ans(i)<<" ";
	}
	cout<<endl;
	// nie zapomnij o ll
	return 0;
}