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
int a[10],b[10];
string f(vi& a){
	string s;
	trav(i,a){
		s+=char(i+'0');
	}
	return s;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s,t;cin>>s>>t;
	vi x;
	trav(i,s) x.pb(i-'0'),a[i-'0']++;
	trav(i,t) b[i-'0']++;
	if(sz(s)<sz(t)) {
		repD(i,9,0){
			rep(j,a[i]) cout<<i;
		}
		return 0;
	}
	sort(all(x));
	int ix = 0;
	string fns;
	bool fg = false;
	trav(i,t){
		ix++;
		int k= i-'0';
		repD(j,9,0){
			auto it = lower_bound(all(x),j);
			if(j<=k&&it!=x.end()&&(*it)==j){
				x.erase(it);
				string y = f(x);
				if(j<k||y<=t.substr(ix,sz(t)-ix)) {
					fns+=char('0'+j);
					if(j<k) fg = true;
					break;
				}
				x.pb(j);
				sort(all(x));
			}
		}
		if(fg) break;
	}
	sort(all(x));
	reverse(all(x));
	trav(i,x) fns+=char('0'+i);
	cout<<fns;



	return 0;
}