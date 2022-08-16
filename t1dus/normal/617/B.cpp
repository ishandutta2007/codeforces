#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 100000000
#define mp make_pair

int main() {
	
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	vi v;
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	    if (a[i]) v.pb(i);
	}
	if (v.empty()) cout << 0 << endl;
	else if (v.size() == 1) cout << 1 << endl;
	else{
	    ll ans = 1;
	    for (int i = 1; i < v.size(); i++){
	        ans *= v[i]-v[i-1];
	    }
	    cout << ans << endl;
	}
}