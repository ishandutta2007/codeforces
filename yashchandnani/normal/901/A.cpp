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
	int s =0 ,p = 1;
	int a[n+1];
	vi v1,v2;
	rep(i,n+1) {
		cin>>a[i];
		rep(j,a[i]) v1.pb(s);
		s+=a[i];
	}
	s =0;
	rep(i,n+1){
		rep(j,a[i]-1) v2.pb(s-p+1);
		v2.pb(s);
		p=a[i];s+=a[i];
	}
	if(v1==v2) cout<<"perfect";
	else{
		cout<<"ambiguous\n";
		trav(i,v1) cout<<i<<' ';
		cout<<"\n";
		trav(i,v2) cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}