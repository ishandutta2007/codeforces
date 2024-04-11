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
	int cnt =0;
	vi v;
	rep(i,n){
		char c;cin>>c;
		if(c=='s') v.pb(cnt);
		else cnt++;
	}
	vi ans[sz(v)+1];
	ans[0].pb(1);
	repA(i,1,sz(v)){
		ans[i].pb(1);
		repA(j,1,v[i-1]){
			if(sz(ans[i-1])>j) ans[i].pb((ans[i].back()+ans[i-1][j])%1000000007);
			else  ans[i].pb(ans[i].back());
		}
	}
	cout<<ans[sz(v)][cnt];
	return 0;
}