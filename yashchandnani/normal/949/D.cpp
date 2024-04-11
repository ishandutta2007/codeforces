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
int a[100009],ee[100009],b[100009],c[100009];
struct Tree {
	typedef int T;
	const T LOW = 0;
	T f(T a, T b) { return a+b; }

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
	T query2(int x) { return que2(1, 0, n,x); }
	T que2(int pos,  int lo, int hi,int x) {
		if(lo+1==hi) return lo;
		int m = (lo+hi)/2;
		if(x<=s[2*pos]) return que2(2*pos,lo,m,x);
		else return que2(2*pos+1,m,hi,x-s[2*pos]);
	}

};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,d,bb;cin>>n>>d>>bb;
	int l = 0,r = n/2;
	int a1 = (n+1)/2,a2=(n/2);
	Tree t(n+1),t2(n+1);
	repA(i,1,n) {
		cin>>a[i];
		b[n-i+1] = a[i];
		t2.update(n-i+1,b[n-i+1]);
		t.update(i,a[i]);
	}
	int req=r*bb;
	int lo1=1,hi1=t.query2(req);
	repA(i,1,hi1){
		c[max(1,(i+d)/(d+1))]+=a[i];
	}
	int x1 = 0;
	repA(i,1,n/2){
		if(c[i]>=bb) c[i]-=bb;
		else x1++;
		c[i+1]+=c[i];
	}
	int lo2=1,hi2=t2.query2(req);
	repA(i,1,hi2){
		ee[max(1,(i+d)/(d+1))]+=b[i];
	}
	int x2 = 0;
	repA(i,1,n/2){
		if(ee[i]>=bb) ee[i]-=bb;
		else x2++;
		ee[i+1]+=ee[i];
	}
	cout<<max(x1,x2);
		
	return 0;
}