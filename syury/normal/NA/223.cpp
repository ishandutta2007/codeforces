//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;
const int B = 350;

struct query{
	int l, r, block, id;
	bool operator < (const query & q)const{
		if(block != q.block)
			return block < q.block;
		else
			return r < q.r;
	}
};

ll A[N];
int n, q;
int a[N];
ll ans = 0;
int cnt[5*N];
query qs[N];

inline void add(int i){
	ans -= a[i] * 1ll * cnt[a[i]] * cnt[a[i]];
	++cnt[a[i]];
	ans += a[i] * 1ll * cnt[a[i]] * cnt[a[i]];
}

inline void del(int i){
	ans -= a[i] * 1ll * cnt[a[i]] * cnt[a[i]];
	--cnt[a[i]];
	ans += a[i] * 1ll * cnt[a[i]] * cnt[a[i]];
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	F(i, 0, n)
		cin >> a[i];
	F(i, 0, q){
		cin >> qs[i].l >> qs[i].r;
		--qs[i].l; --qs[i].r;
		qs[i].id = i;
		qs[i].block = qs[i].l/B;
	}
	sort(qs, qs + q);
	int L, R;
	L = qs[0].l; R = qs[0].r;
	E(i, L, R){
		add(i);
		A[qs[0].id] = ans;
	}
	F(i, 1, q){
		while(R < qs[i].r){
			add(++R);
		}
		while(R > qs[i].r){
			del(R--);
		}
		while(L < qs[i].l)
			del(L++);
		while(L > qs[i].l)
			add(--L);
		A[qs[i].id] = ans;
	}
	F(i, 0, q)
		cout << A[i] << '\n';
	return 0;
}