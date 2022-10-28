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

struct Tree {
	typedef int T;
	const T LOW = 0;
	T f(T a, T b) { return __gcd(a,b); }

	int n;
	vi s;
	Tree() {}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r) { return que(1, l, r, 0, n); }
	T que(int pos, int l, int r, int lo, int hi) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r) return s[pos];
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m),
				que(2 * pos + 1, l, r, m, hi));
	}
	bool ask(int l,int r,int x){
		if(l>=r-1) return true;
		int m = (l+r)/2;
		if(query(l,m)%x==0) return ask(m,r,x);
		else if(query(m,r)%x==0) return ask(l,m,x);
		else return false;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	Tree t(n);
	int a[n];
	rep(i,n){
		cin>>a[i];t.update(i,a[i]);
	}
	int q;cin>>q;
	rep(i,q){
		int typ;cin>>typ;
		if(typ==1){
			int l,r,x;cin>>l>>r>>x;
			if(t.ask(l-1,r,x)) cout<<"YES\n";
				else cout<<"NO\n";
		}
		else{
			int pos,val;
			cin>>pos>>val;
			t.update(pos-1,val);
		}
	}
	return 0;
}