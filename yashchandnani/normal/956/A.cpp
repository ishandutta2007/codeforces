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
	int n,m;cin>>n>>m;
	vi a[n];

	rep(i,n){
		rep(j,m){
			char c;cin>>c;
			if(c=='#') a[i].pb(1);
			else a[i].pb(0);
		}
	}
	bool f = true;
	rep(i,n){
		rep(j,i){
			if(a[i]!=a[j]){
				rep(k,m){
					if(a[i][k]==1&&a[j][k]==1) f = false;
				}
			}
		}
	}
	if(f) cout<<"Yes";
	else cout<<"No";

	return 0;
}