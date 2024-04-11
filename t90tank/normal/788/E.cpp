#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 
template<class T> using rset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define mp make_pair

const int maxn = 200006; 
const ll mod = (ll)1e9+7;

struct val {
	ll a[3][3];
	val() {memset(a, 0, sizeof(a));}
	val(ll l, ll m, ll r) {
		memset(a, 0, sizeof(a)); 
		a[0][0] = l; 
		a[1][1] = m; 
		a[2][2] = r; 
	}
	val operator+(val &y) {
		val ret; 
		for (int i = 0; i <= 2; ++i) 
			for (int j = i; j <= 2; ++j) {
				ret.a[i][j] = (a[i][j]+y.a[i][j]) % mod; 
				for (int k = i; k < j; ++k) 
					(ret.a[i][j] += (a[i][k]*y.a[k+1][j])) %= mod; 
			}
		return ret; 
	}
};

int n;
int a[maxn]; 
rset<pair<int,int>> S; 
int sl[maxn], sr[maxn]; 
bool use[maxn]; 
int num_seg[maxn]; 

struct segtree {
	vector<val> T; 
	int n; 
	void build(int n) {
		T = vector<val>(n*2+1);
		this->n = n; 
	}
	#define m (l+r)/2
	#define oddr(l,r) (((l)+(r))|((l)!=(r)))
	void update(int l, int r, int x, int no) {
		if (l == r) {
			if (use[no]) T[oddr(l,r)] = val(sl[no], 1, sr[no]); 
			else T[oddr(l,r)] = val(); 
			return; 
		}
		if (x <= m) update(l, m, x, no); 
		else update(m+1, r, x, no); 
		T[oddr(l,r)] = T[oddr(l,m)]+T[oddr(m+1,r)]; 
	}
	ll total() {
		return T[oddr(1,n)].a[0][2]; 
	}
	#undef m
}; 

map<int,segtree> H; 
map<int,int> num;  
ll ans; 

void update(int x) {
	(ans -= H[a[x]].total()) %= mod; 
	H[a[x]].update(1, num[a[x]], num_seg[x], x); 
	(ans += H[a[x]].total()) %= mod; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]); 
	S.clear();
	for (int i = 1; i <= n; ++i) {
		S.insert(mp(a[i],i)); 
		sl[i] = S.order_of_key(mp(a[i],i));  
		//cout<<sl[i]<<endl;
	}
	S.clear(); 
	for (int i = n; i >= 1; --i) {
		S.insert(mp(a[i],n-i+1)); 
		sr[i] = S.order_of_key(mp(a[i],n-i+1));  
		//cout<<sr[i]<<endl;
	}
	for (int i = 1; i <= n; ++i) {
		num[a[i]]++; 
		num_seg[i] = num[a[i]]; 
	}
	for (auto p : num) H[p.first].build(p.second); 
	ans = 0; 
	for (int i = 1; i <= n; ++i) {
		use[i] = true; 	
		update(i); 
	}
	int m; 
	scanf( "%d", &m ); 
	for (int i = 1; i <= m; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		use[b] = !use[b]; 
		update(b); 
		printf( "%lld\n", (ans+mod) %mod ); 
	}
}