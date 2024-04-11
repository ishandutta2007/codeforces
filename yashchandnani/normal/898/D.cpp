#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m,k;cin>>n>>m>>k;
	vector<int> cl;
	rep(i,n){
		int x;cin>>x;
		cl.pb(x);
	}
	sort(all(cl));
	vector<int> ans;
	trav(i,cl){
		int tot = ans.end()-lower_bound(all(ans),i-m+1);
		if(tot+1<k) ans.pb(i);
	}
	cout<<sz(cl)-sz(ans);

	return 0;
}