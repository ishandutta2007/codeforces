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
vector<vi> m;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,a,b;cin>>n>>a>>b;
	if(a!=1&&b!=1||((n==2||n==3)&&a==1&&b==1)){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	int x = a;
	if(x==1) x=b;
	rep(i,n){
		vi t(n,0);m.pb(t);
	}
	if(a==1&&b==1){
		rep(i,n-1) m[i][i+1]=1,m[i+1][i]=1;
	}
	else rep(i,n-x+1){
		rep(j,n-x+1){
			if(i!=j) m[i][j] = 1;
		}
	}

	if(x==a) {
		rep(i,n) {
			rep(j,n) cout<<m[i][j];
			cout<<'\n';
		}
	}
	else{
		rep(i,n) {
			rep(j,n) {
				if(i==j) cout<<0;
				else cout<<1-m[i][j];
			}
			cout<<'\n';
		}
	}
	return 0;
}