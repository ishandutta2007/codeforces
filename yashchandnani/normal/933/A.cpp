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
int ans[2009][2009];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	vector<pii> v;
	v.pb(mp(1,0));
	rep(i,n){
		int x;cin>>x;
		if(x==v.back().fst) v.back().snd++;
		else v.pb(mp(x,1));
	}
	if(v.back().fst!=2) v.pb(mp(2,0));
	if(sz(v)==2){
		cout<<v[0].snd+v[1].snd;
	}
	else{
		int s = sz(v);
		int fns = 0;
		for(int i=0;i<sz(v);i+=2){
			ans[i][i+1] = v[i].snd+v[i+1].snd;
			int j=i+3;
			int x= v[i].snd;
			for(;j<s;j+=2){
				x+=v[j-1].snd;
				ans[i][j] = max(ans[i][j-2],x)+v[j].snd;
			}
		}
		for(int i=1;i<sz(v);i+=2){
			fns = max(fns,ans[0][i]+ans[i+1][s-1]);
		}
		cout<<fns;
	}


	return 0;
}