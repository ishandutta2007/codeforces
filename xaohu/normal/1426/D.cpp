#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
typedef long long ll;	
using namespace std;

const int N = 2e5 + 10;

int n, a;
ll s;
map<ll, int> lst;
vector<int> v[N];

int main() {
	cin >> n;
	lst[s] = 0;
	rep(i, 1, n + 1) {
		cin >> a;
		s += a;
		if (lst.count(s)) 
			v[i].push_back(lst[s] + 1);		
		lst[s] = i;
	}
	int last = 0, res = 0;
	rep(i, 1, n + 1) {
		for (auto j : v[i])
			if (last <= j) {
				last = i;
				res++;
			}
	}
	cout << res << "\n";
	return 0;
}