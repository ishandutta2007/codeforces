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
	int n;cin>>n;
	int m[n];
	vi a;
	int mx = -1;
	rep(i,n) {
		cin>>m[i];
		if(m[i]>mx) a.pb(i),mx = m[i];
	}
	int px = 0;
	ll ans = 0;
	repD(i,n-1,0){
		px = max(px-1,m[a.back()]+1);
		if(i==a.back()) a.pop_back();
		ans+=px-m[i]-1;
	}
	cout<<ans;
	return 0;
}