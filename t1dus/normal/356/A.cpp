#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second


int main() {
	
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
    int ans[n+1];
    for (int i = 1; i <= n; i++) ans[i] = 0;
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	while (m --){
	    int l,r,x;
	    cin >> l >> r >> x;
	    for (auto it = s.lower_bound(l); it != s.end(); it++){
	        if (*it > r) break;
	        if (*it == x) continue;
	        ans[*it] = x;
	    }
	    auto it1 = s.lower_bound(l);
	    auto it2 = s.upper_bound(r);
	    s.erase(it1,it2);
	    s.insert(x);
	}
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}