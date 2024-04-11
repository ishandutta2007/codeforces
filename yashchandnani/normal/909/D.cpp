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
	string s;cin>>s;
	vector<pii> v;
	v.pb(mp(1,s[0]-'a'));
	repA(i,1,sz(s)-1){
		if(s[i]-'a'==v.back().snd) v.back().fst++;
		else v.pb(mp(1,s[i]-'a'));
	}
	int ans=0;
	while(sz(v)>1){
		ans++;
		vector<pii> n;
		rep(i,sz(v)){
			int rm = 2;
			if(i==0||i==sz(v)-1) rm=1;
			pii z = v[i];
			z.fst-=rm;
			if(z.fst<=0) continue;
			if(!n.empty()){
				if(z.snd==n.back().snd) n.back().fst+=z.fst;
				else n.pb(z);
			}
			else n.pb(z);
		}
		v.clear();
		v = n;
	}
	cout<<ans;
	
	
	return 0;
}