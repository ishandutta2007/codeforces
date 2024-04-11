#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
const int maxn = 200006; 
#define fir first
#define sec second 
const ll oo = 0x3f3f3f3f3f3f3f3fll; 

struct Val {
	ll mind, lazy;
	Val () {mind = lazy = 0;}
}; 

struct Seg {
	Val e[maxn*4]; 
	void upd(int T) {
		e[T].mind = min(e[T*2].mind, e[T*2+1].mind); 
	}
	void down(int T) {
		e[T*2].lazy += e[T].lazy; 
		e[T*2].mind += e[T].lazy; 
		e[T*2+1].lazy += e[T].lazy; 
		e[T*2+1].mind += e[T].lazy; 
		e[T].lazy = 0; 
	}
	void clear() {
		memset(e, 0, sizeof(e)); 
	}
	void add(int T, int l, int r, int a, int b, ll c) {
		if (a > b) return; 
		if (a <= l && b >= r) {
			e[T].lazy += c; 
			e[T].mind += c; 
			return; 
		}
		down(T); 
		int m = (l+r) / 2; 
		if (a <= m) add(T*2,l,m,a,b,c); 
		if (b > m) add(T*2+1,m+1,r,a,b,c); 
		upd(T); 
	}
	ll ask(int T, int l, int r, int a, int b) {
		//cout<<T<<' '<<l<<' '<<r<<' '<<a<<' '<<b<<endl;
		if (a > b) return oo; 
		if (a <= l && b >= r) return e[T].mind; 
		int m = (l+r)/2;
		ll ret = oo; 
		down(T); 
		if (a <= m) ret = min(ret, ask(T*2,l,m,a,b)); 
		if (b > m) ret = min(ret, ask(T*2+1,m+1,r,a,b)); 
		return ret; 
	}
}; 

struct {
	Seg s[2]; 
	int n[2]; 
	void clear(int N) {
		s[0].clear(); s[1].clear(); 
		n[0] = N/2; 
		n[1] = (N+1)/2;
	}
	int Num(int x) { return (x+1)/2; }
	ll Get(int x) {
		if (x == 0) return 0; 
		if (x % 2 == 0) return s[0].ask(1,1,n[0],Num(x),Num(x)); 
		return s[1].ask(1,1,n[1],Num(x),Num(x)); 
	}
	void add_(int a, ll c) {
		if (a % 2 == 0) {
			s[1].add(1, 1, n[1], 1, Num(a-1), c); 
		}
		else {
			s[1].add(1, 1, n[1], 1, n[1], c); 
			s[0].add(1, 1, n[0], Num(a+1), n[0], -c);  
		}
	}
	void add(int a, int b, ll c) {
		add_(b, c); 
		add_(a-1, -c); 
	}
	ll real(int d) {
		if (d % 2 == 0) return -1; 
		return 1; 
	}
	bool check(int a, int b) {
		ll sol = Get(a-1)-1; 
		if (Get(b)+real(b-(a-1))*sol != 1) return false; 
		int l[2], r[2]; 
		if (a % 2 == 0) {l[0] = Num(a); l[1] = Num(a+1);}
		else {l[0] = Num(a+1); l[1] = Num(a);}
		if (b % 2 == 0) {r[0] = Num(b); r[1] = Num(b-1);}
		else {r[0] = Num(b-1); r[1] = Num(b);}
		if (l[0] <= r[0] && s[0].ask(1,1,n[0],l[0],r[0])+real(l[0]*2-(a-1))*sol < 0) return false; 
		if (l[1] <= r[1] && s[1].ask(1,1,n[1],l[1],r[1])+real(l[1]*2-1-(a-1))*sol < 0) return false; 
		return true; 
	}
}T; 

int n, m;

int main() {
	scanf("%d", &n); 
	T.clear(n); 
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf( "%d", &x ); 
		T.add(i,i,x*2); 
	}
	scanf("%d", &m); 
	for (int i = 1; i <= m; ++i) {
		int op, a, b, c; 
		scanf( "%d", &op ); 
		if (op == 1) {
			scanf( "%d%d%d", &a, &b, &c ); 
			a++; b++; 
			T.add(a, b, c*2); 
		}
		else {
			scanf( "%d%d", &a, &b ); 
			a++; b++; 
			//if (T.check(a,b)) cout<<"yes\n"; 
			printf( "%d\n", T.check(a,b) ); 
		}
	}
}