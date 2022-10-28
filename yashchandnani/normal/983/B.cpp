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
int ans[5009][5009];
int b[5009],a[5009],c[5009][5009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n) c[i][i] = a[i],ans[i][i]=a[i];
	repA(i,1,n-1){
		rep(j,n-i){
			c[j][j+i] = c[j][j+i-1]^c[j+1][j+i];
		}
	}
	repA(i,1,n-1){
		rep(j,n-i){
			ans[j][j+i] = max(ans[j][j+i-1],max(ans[j+1][j+i],c[j][j+i]));
		}
	}
	int q;cin>>q;
	rep(i,q){
		int l,r;cin>>l>>r;
		cout<<ans[l-1][r-1]<<'\n';
	}
	
	return 0;
}