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
	int t;cin>>t;
	rep(i,t){
		int n,k;cin>>n>>k;
		int a[k];
		rep(j,k) cin>>a[j];
		int ans = max(a[0],n-a[k-1]+1);
		rep(j,k-1){
			int l = a[j+1]-a[j];
			ans = max(ans,l/2+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}