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
typedef pair<pii,int> pll;
typedef vector<int> vi;
ll chng[200009];
int cnt[200009];
vector<pii> prob;
vector<pll> asn;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,t;cin>>n>>t;
	rep(i,n){
		int a,x;cin>>a>>x;
		prob.pb(mp(x,a));
		asn.pb(mp(mp(x,a),i+1));
	}
	sort(asn.rbegin(),asn.rend());
	sort(prob.rbegin(),prob.rend());
	bool ans = true;
	int fns = 0;
	ll tm = 0;
	repA(i,1,n){
		tm-=chng[i-1];
		int req = 1+cnt[i-1];
		ans = true;
		while(req){
			if(prob.empty()) {
				ans = false;
				break;
			}
			pii z = prob.back();
			prob.pop_back();
			if(z.snd>=i){
				chng[z.snd]+=z.fst;
				cnt[z.snd]++;
				tm+=z.fst;
				req--;
			}
		}
		if(!ans||tm>t) break;
		else fns++;
	}
	rep(i,2) cout<<fns<<'\n';
	int fan = fns;
	while(fns){
		pll z = asn.back();
		asn.pop_back();
		if(z.fst.snd>=fan) {
			cout<<z.snd<<' ';
			fns--;
		}

	}
	return 0;
}