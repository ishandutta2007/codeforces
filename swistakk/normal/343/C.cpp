#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define ll long long int
#define MP make_pair
#define PB push_back

using namespace std;

const int N = 1000 * 1000;

ll h[N];
ll t[N];

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	ll n, m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>h[i];
	}
	for (int i = 1; i <= m; i++) {
		cin>>t[i];
	}
	ll kl = 0, kp = 1000 * 1000;
	kp *= kp;
	ll aktc, faj;
	while (kl <= kp) {
		aktc = (kl + kp) / 2;
		int to_be_read = 1;
		for (int i = 1; i <= n; i++) {
			if (to_be_read == m + 1) {
				break;
			}
			ll dis = h[i] - t[to_be_read];
			if (dis > aktc) {
				break;
			}
			dis = max(dis, 0ll);
			ll prawo = max(aktc - 2 * dis, (aktc - dis) / 2);
			while (to_be_read <= m && t[to_be_read] <= h[i] + prawo) {
				to_be_read++;
			}
		}
		if (to_be_read == m + 1)
		{
			faj = aktc;
			kp = aktc - 1;
		}
		else
		{
			kl = aktc + 1;
		}
	}
	cout << faj << endl;
	
	
	
	
	
	
	
	
	
	// nie zapomnij o ll
	return 0;
}