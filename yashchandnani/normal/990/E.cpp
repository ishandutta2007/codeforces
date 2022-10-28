#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
int a[1000009];
bool chk[1000009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,k;cin>>n>>m>>k;
	ll ans = 1e16;
	vi s;
	int p = -2,px = 0,ix=0;
	rep(i,m) {
		int x;cin>>x;
		chk[x]=1;
		if(x==p+1) px++;
		else px = 1,s.pb(x);
		ix = max(ix,px);
		p = x;
	}
	rep(i,k) cin>>a[i+1];
	if(chk[0]||ix>=k) {
		cout<<-1;return 0;
	}
	repA(i,ix+1,k){
		int j = 0,cnt=1;
		while(j+i<n){
			j = j+i;
			if(chk[j]){
				int k = upper_bound(all(s),j)-s.begin();
				j = s[k-1]-1;
			}
			cnt++;
		}
		ans = min(ans,1ll*cnt*a[i]);
	}
	cout<<ans;
		
	return 0;
}