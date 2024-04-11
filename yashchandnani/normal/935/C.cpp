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
typedef long double ld;
typedef pair<ld, ld> pii;
typedef vector<int> vi;

ld dist(pii a,pii b){
	return sqrt((a.fst-b.fst)*(a.fst-b.fst)+(a.snd-b.snd)*(a.snd-b.snd));
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ld R,x1,x2,y1,y2;cin>>R>>x1>>y1>>x2>>y2;
	pii a = mp(x1,y1);
	pii b = mp(x2,y2);
	cout<<setprecision(20);
	if(x1==x2&&y1==y2){
		cout<<x1+R/2<<' '<<y1<<' '<<R/2;
	}
	else if(dist(a,b)>R) cout<<x1<<' '<<y1<<' '<<R;
	else {
		ld t = dist(a,b)+R;
		t/=2;
		pii c = mp(a.fst-b.fst,a.snd-b.snd);
		ld z = dist(c,mp(0,0));
		c.fst*=t/z;
		c.snd*=t/z;
		cout<<b.fst+c.fst<<' '<<b.snd+c.snd<<' '<<t;
	}
	return 0;
}