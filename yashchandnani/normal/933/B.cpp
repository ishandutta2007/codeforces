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
	ll p,k;cin>>p>>k;
	vi ans;
	while(p>=k){
			ans.pb(p-(p/k)*k);
			p=p/k;
			ans.pb((p+k-1)/k*k-p);
			p=(p+k-1)/k;
	}
	ans.pb(p);
	while(!ans.empty()&&ans.back()==0) ans.pop_back();
	if(ans.empty()) cout<<1<<'\n'<<0;
	else{
		cout<<sz(ans)<<'\n';
		trav(i,ans) cout<<i<<' ';
	}
	return 0;
}