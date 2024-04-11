#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, b, k;
string s, t;
set<int> nums;
vector<int> answers;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--) {
		int x, ans;
		cin >> x;
		if(x%2) ans = x/2;
		else ans = x/2-1;
		cout << ans << '\n';

	}

}