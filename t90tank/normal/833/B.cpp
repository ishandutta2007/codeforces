#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

struct val {
	int add, maxd; 
};

const int maxn = 35006; 
struct Seg {
	val e[maxn*20]; 
	void upd(int T) {
		e[T].maxd = max(e[T*2].maxd, e[T*2+1].maxd)+e[T].add; 
	}
	void down(int T) {
		e[T*2].add += e[T].add; 
		e[T*2].maxd += e[T].add; 
		e[T*2+1].add += e[T].add;
		e[T*2+1].maxd += e[T].add; 
		e[T].add = 0; 
	}
	void add(int T, int l, int r, int a, int b, int c) {
		if (a <= l && b >= r) {
			e[T].add+=c; 
			e[T].maxd+=c;
			return; 
		}
		int m = (l+r)/2; 
		down(T); 
		if (a <= m) add(T*2,l,m,a,b,c); 
		if (b > m) add(T*2+1,m+1,r,a,b,c); 
		upd(T); 
	}
	int getmax(int T, int l, int r, int a, int b) {
		if (a <= l && b >= r) return e[T].maxd; 
		int m = (l+r)/2;
		int ret = -0x3f3f3f3f;  
		if (a <= m) ret = max(ret, getmax(T*2,l,m,a,b)); 
		if (b > m) ret = max(ret, getmax(T*2+1,m+1,r,a,b)); 
		return ret; 
	}
	void build(int T, int l, int r,int f[]) {
		e[T].add = 0; 
		if (l == r) {
			e[T].maxd = f[l]; 
			return; 
		}
		int m = (l+r)/2; 
		build(T*2,l,m,f); 
		build(T*2+1,m+1,r,f);
		upd(T); 
	}
}T; 

int f[maxn], g[maxn]; 
map<int,int> S; 
int a[maxn];
int b[maxn]; 
int n, m;

int main() {
	scanf( "%d%d", &n, &m );
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); 
		b[i] = S[a[i]]; 
		S[a[i]] = i; 
	}
	for (int i = 1; i <= n; ++i) f[i] = f[i-1] + (b[i]==0); 
	for (int i = 2; i <= m; ++i) {
		T.build(1,1,n,f); 
		for (int j = 1; j < i; ++j) f[j] = -0x3f3f3f3f; 
		for (int j = i; j <= n; ++j) {
			T.add(1,1,n,max(1,b[j]),j-1,1); 
			f[j] = T.getmax(1,1,n,1,j-1); 
		}	
	}
	cout<<f[n]<<endl; 
}