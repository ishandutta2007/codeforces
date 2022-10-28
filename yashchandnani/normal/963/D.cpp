#include <bits/stdc++.h>
using namespace std;

#define rep(i,a, n)    for(int i = a; i < (n); ++i)
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
typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) { // (optional)
	//this is just 3 times faster than stl sort for N=10^6
	int mask = (1 << bits) - 1;
	rep(it,0,2) {
		int move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		rep(i,0,sz(b))
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pli> res(b.size());
		rep(i,0,sz(b))
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pli> b(N);
		a.resize(N);
		rep(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
			a[b[0].second] = 0;
			rep(i,1,N)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			rep(i,0,N) {
				b[i].first = (ll)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	int lower_bound(string t){
		int l = 1,r=sz(a);
		while(l<r){
			int m = (l+r)/2;
			if(s.substr(a[m],min(sz(s)-1-a[m],sz(t)+1)) >= t) r = m;
			else l = m+1;
		}
		return l;
	}
	int upper_bound(string t){
		int l = 1,r=sz(a);
		while(l<r){
			int m = (l+r)/2;
			if(s.substr(a[m],min(sz(a)-1-a[m],sz(t))) > t) r = m;
			else l = m+1;
		}
		return l;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		rep(i,0,n) inv[a[i]] = i;
		rep(i,0,n) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;cin>>s;
	SuffixArray t(s);
	int q;cin>>q;
	rep(i,0,q){
		int k;string m;cin>>k>>m;
		vi occ;
		int st = t.lower_bound(m),en = t.upper_bound(m);
		repA(i,st,en-1){
			occ.pb(t.a[i]);
		}
		sort(all(occ));
		int ans = -1;
		repA(i,k-1,sz(occ)-1)
			if(ans==-1||ans>occ[i]-occ[i-k+1]+sz(m)) ans = occ[i]-occ[i-k+1]+sz(m);
		cout<<ans<<'\n';
	}

	return 0;
}