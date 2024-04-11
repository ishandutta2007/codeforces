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
	int a[48] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	vi c[36],x(24);
	rep(i,12){
		repA(j,i,i+23){
			c[i].pb(a[j]);
		}
	}
	a[1] = a[25] = 29;
	rep(i,24){
		repA(j,i,i+23){
			c[i+12].pb(a[j]);
		}
	}
	int n;cin>>n;
	rep(i,n){
		cin>>x[i];
	}
	x.resize(n);
	rep(i,36){
		c[i].resize(n);
		if(x==c[i]) {cout<<"YES";return 0;}
	}
	cout<<"NO";


	
	return 0;
}