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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	ll u,e[n];
	cin>>u;
	rep(i,n) cin>>e[i];
	int j=2;
	ld ans = -1,t=1;
	rep(i,n){
		while(j+1<n&&e[j+1]-e[i]<=u) j++;
		if(j>i+1&&j<n&&e[j]-e[i]<=u&&e[j]>e[i]) ans = max(ans,t*(e[j]-e[i+1])/(e[j]-e[i]));
	}
	cout<<setprecision(20)<<ans;
	return 0;
}