#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	vector<int> aOnly, bOnly;
	while(n--) {
		int x;
		string y;
		cin >> x >> y;
		if(y[0] == 'U') aOnly.push_back(x);
		else bOnly.push_back(x);
	}
	sort(aOnly.begin(), aOnly.end());
	sort(bOnly.begin(), bOnly.end());
	int ai = 0;
	int bi = 0;
	ll aRet = 0;
	ll bRet = 0;
	while(a--) {
		if(ai < aOnly.size()) {
			aRet++;
			bRet += aOnly[ai++];
		}
	}
	while(b--) {
		if(bi < bOnly.size()) {
			aRet++;
			bRet += bOnly[bi++];
		}
	}
	vector<int> rem;
	while(ai < aOnly.size()) rem.push_back(aOnly[ai++]);
	while(bi < bOnly.size()) rem.push_back(bOnly[bi++]);
	sort(rem.begin(), rem.end());
	for(int i = 0; i < c && i < rem.size(); i++) {
		aRet++;
		bRet += rem[i];
	}
	cout << aRet << " " << bRet << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}