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
typedef long double ld;
ld dist(ld x1,ld x2,ld y1,ld y2){
	ld x = abs(x1-x2);
	ld y = abs(y1-y2);
	return sqrt(x*x+y*y);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;ld d;cin>>n>>d;
	cout<<setprecision(20);
	ld r[n];
	d*=2;
	ld y[n];
	rep(i,n) cin>>r[i];
	rep(i,n){
		ld ans = d/2;
		rep(j,i){
			if(abs(r[j]-r[i])>d+1e-13) continue;
			ld s = y[j],e = 5000009;
			rep(k,100){
				ld m = (s+e)/2;
				if(dist(r[j],r[i],y[j],m)>d+1e-13) e = m;
				else s = m;
			}
			ans = max(ans,s);
		}
		y[i] = ans;
		cout<<ans<<' ';
	}
	return 0;
}