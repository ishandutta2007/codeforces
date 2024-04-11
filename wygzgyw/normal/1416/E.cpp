#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
int T,n,ans;
struct node {
	ll k=1,b=0;
	set<ll> s;
	pair<ll,ll> seg={1,0};
	void init(int mx) {
		s.clear(); k=1,b=0;
		seg=make_pair(1,mx);
	}
	void setpush(int x) {
		init(0); s.insert(x);
	}
	void rotate(int x) {
		b=x-b,k=-k;
		seg=make_pair(x-seg.second,x-seg.first);
	}
	ll f(ll x) { return k*x+b; }
	ll anti(ll x) { return k*(x-b); }
	bool in(ll x) {
		if (s.count(anti(x))) return 1;
		return seg.first<=x&&x<=seg.second;
	}
	void push(ll x) {
		s.insert(anti(x));
	}
	set<ll>::iterator get() {
		if (k==1) return prev(s.end());
		return s.begin();
	}
	void pop(ll x) {
		seg.second=min(seg.second,x);
		while (!s.empty()&&f(*get())>x) s.erase(get());
	}
	bool empty() {
		return s.empty()&&seg.first>seg.second;
	}
} now;
int main() {
	//freopen("1.txt","r",stdin);
	read(T); int x;
	while (T--) {
		read(n);
		now.init(0); ans=0;
		for (int i=1;i<=n;i++) {
			read(x);
			now.pop(x-1);
			if (x%2==0&&now.in(x/2)) {
				ans+=2,now.setpush(x/2);
			} else if (now.empty()) {
				if (x%2==0) ans++,now.setpush(x/2);
				else now.init(x-1);
			} else {
				ans++;
				if (x%2==0) now.push(x/2);
			}
			now.rotate(x);
		}
		printf("%d\n",n*2-ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/