#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cmath>
#include <cassert>

using namespace std;

typedef long long ll;			//  ll - signed int64
typedef unsigned long long ull;	// ull - unsigned int64
typedef double df;				//  df - double
typedef long double lf;			//  lf - long double

const int  N = 1007;

int n, x[N], y[N], ax[N], ay[N], tx, ty;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	queue<int> qx, qy;
	for(int i = 0; i < n; ++i)
		cin >> ax[i] >> ay[i];
	
	map<pair<int, int>, int> am;
	for(int i = 0; i < n; ++i)
		am[make_pair(x[0]+ax[i], y[0]+ay[i])] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(am.count(make_pair(x[i]+ax[j], y[i]+ay[j])) == 0)
				continue;
			if(++am[make_pair(x[i]+ax[j], y[i]+ay[j])] == n)  {
				qx.push(x[i]+ax[j]);
				qy.push(y[i]+ay[j]);
			}
		}
	}

	while(!qx.empty()) { // O(N^2 log N)
		int cx = qx.front(); qx.pop();
		int cy = qy.front(); qy.pop();

		set< pair<int, int> > dx;
		for(int i = 0; i < n; ++i)
			dx.insert({cx - x[i], cy - y[i]});

		if(dx.size() == n) {
			cout << cx << ' ' << cy << endl;
			return 0;
		}
	}
}