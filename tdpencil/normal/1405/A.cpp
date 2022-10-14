#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define FOR(i, a) for(int i = 0; i < a; i++)
ll n, a, b, c, d, e;
string s;
int t, g, i;
const int INF = 1e9;
int ar[100000];
void tc() {
	cin >> a; 
	vi vals(a);
	FOR(i, a)
		cin >> vals[i];
	reverse(vals.begin(), vals.end());
	FOR(i, a) {
		cout << vals[i] << " ";
	}
	cout << endl;
}
	
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	while(n--) {
		tc();
	}
	return 0;
}