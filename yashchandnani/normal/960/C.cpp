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
typedef vector<ll> vi;
map<int,int> m;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll st = 1;
	int x,d;cin>>x>>d;
	int z = 1<<30;
	vi ans;
	rep(i,31) m[1<<i] = i;
	while(x){
		while(x<z-1) z/=2;
		rep(i,m[z]) ans.pb(st);
		x-=z-1;st+=d;
	}
	if(sz(ans)<=10000) {
		cout<<sz(ans)<<'\n';
		trav(i,ans) cout<<i<<' ';
	}
	else cout<<-1;
	return 0;
}