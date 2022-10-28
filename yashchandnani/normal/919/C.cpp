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
vi r[2009],col[2009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m,k;cin>>n>>m>>k;
	if(k==1){
		int ans =0;
		repA(i,1,n){
			rep(j,m){
				char c;cin>>c;
				if(c=='.') ans++;
			}
		}
		cout<<ans;return 0;
	}
	repA(i,1,m) col[i].pb(0);
	repA(i,1,n) r[i].pb(0);
	repA(i,1,n){
		repA(j,1,m){
			char c;cin>>c;
			if(c=='*') {
				r[i].pb(j);
				col[j].pb(i);
			}
		}
	}
	repA(i,1,m) col[i].pb(n+1);
	repA(i,1,n) r[i].pb(m+1);
	int ans = 0;
	repA(i,1,n){
		rep(j,sz(r[i])-1){
			int l = max(r[i][j+1]-r[i][j],k);
			ans+= l -k;
		}
	}
	repA(i,1,m){
		rep(j,sz(col[i])-1){
			int l = max(col[i][j+1]-col[i][j],k);
			ans+= l -k;
		}
	}
	cout<<ans;

	return 0;
}