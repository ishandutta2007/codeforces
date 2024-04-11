#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

ll w[1001 * 1001];

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	uint n, l, r, ql, qr;
	cin>>n>>l>>r>>ql>>qr;
	uint sum = 0;
	for (int i = 1; i <= n; i++) {
		cin>>w[i];
		sum += w[i];
	}
	ll res = 1001 * 1001 * 1001;
	res *= res;
	ll acc = 0;
	for (int i = 0; i <= n; i++) {
		if (i) {
			acc += w[i];
		}
		if (2 * i < n) {
			res = min(res, acc * l + (sum - acc) * r + max(0ll, (n - 2 * i - 1)) * qr);
		} else {
			res = min(res, acc * l + (sum - acc) * r + max(0ll, (2 * i - n - 1)) * ql);
		}
	}
	cout<<res<<endl;
	
	// nie zapomnij o ll
	return 0;
}