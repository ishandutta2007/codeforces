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
	vector<int> ans1,ans2;
	rep(i,n){
		int x;cin>>x;
		int y = sqrt(x);
		if(y*y==x){
			if(x==0) ans2.pb(2);
			else ans2.pb(1);
		}
		else{
			ans1.pb(min(x-y*y,(y+1)*(y+1)-x));
		}
	}
		ll ans =0;
	if(sz(ans1)>sz(ans2)){
		int diff = n/2-sz(ans2);
		sort(all(ans1));
		rep(i,diff) ans+=ans1[i];
	}
	else{
		int diff = n/2-sz(ans1);
		sort(all(ans2));
		rep(i,diff) ans+=ans2[i];
	}
	cout<<ans;
	return 0;
}