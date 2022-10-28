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
	int n,p,l,r;cin>>n>>p>>l>>r;
	if(l==1){
		if(r==n) cout<<0;
		else cout<<abs(r-p)+1;
	}
	else {
		if(r==n) cout<<abs(l-p)+1;
		else{
			int ans = r-l+2;
			ans+=min(abs(l-p),abs(r-p));
			cout<<ans;
		}
	}
	return 0;
}