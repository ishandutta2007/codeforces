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
	map<string,vector<string> > m;
	rep(i,n){
		string nam;cin>>nam;
		int mm;cin>>mm;
		rep(j,mm){
			string t;cin>>t;
			m[nam].pb(t);
		}
	}
	cout<<sz(m)<<'\n';
	trav(it,m){
		cout<<it.fst<<' ';
		set<string> ans;
		trav(k,it.snd){
			ans.insert(k);
		}
		vector<string> fns;
		trav(k,ans){
			string l = k;reverse(all(l));
			bool f = false;
			trav(kk,ans){
				string ll = kk;reverse(all(ll));
				if(sz(ll)>sz(l)&&ll.find(l)==0) {f= true;break;}
			}
			if(!f) fns.pb(k);
		}

		cout<<sz(fns)<<' ';
		trav(j,fns){
			cout<<j<<' ';
		}
		cout<<'\n';
	}


	return 0;
}