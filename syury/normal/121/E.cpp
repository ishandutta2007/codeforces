#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; i++)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; i--)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int N = (int)1e5 + 5;
const int D = (int)1e4 + 5;
const int SQ = (int)350;

int a[N];

struct block{
	int cnt[D];
	int added = 0;
	int l, r;
	void push(){
		F(i, l, r + 1){
			--cnt[a[i]];
			a[i] += added;
			++cnt[a[i]];
		}
		added = 0;
	}
};

block b[N/SQ + 3];
int n, q, sz;

void build(){
	int la = 0;
	sz = 0;
	F(i, 0, n){
		if(i - la + 1 >= SQ || i + 1 == n){
			b[sz].l = la;
			b[sz].r = i;
			F(j, la, i + 1)
				b[sz].cnt[a[j]]++;
			++sz;
			la = i + 1;
		}
	}
}

vector<int> nums;
bool G[D];

bool is_good(int x){
	if(!x)ret 0;
	while(x){
		if(x%10 != 4 && x%10 != 7)
			ret 0;
		x /= 10;
	}
	ret 1;
}

int get(int l, int r){
	int ans = 0;
	F(bl, 0, sz){
		if(l > b[bl].r || r < b[bl].l)cont;
		if(l <= b[bl].l && r >= b[bl].r){
			I(x, nums){
				if(x - b[bl].added >= 0)
					ans += b[bl].cnt[x - b[bl].added];
			}
			cont;
		}
		b[bl].push();
		int L = max(l, b[bl].l), R = min(r, b[bl].r);
		F(i, L, R + 1)
			ans += G[a[i]];
	}
	ret ans;
}

void add(int l, int r, int x){
	F(bl, 0, sz){
		if(l > b[bl].r || r < b[bl].l)cont;
		if(l <= b[bl].l && r >= b[bl].r){
			b[bl].added += x;
			cont;
		}
		b[bl].push();
		int L = max(l, b[bl].l), R = min(r, b[bl].r);
		F(i, L, R + 1){
			--b[bl].cnt[a[i]];
			a[i] += x;
			++b[bl].cnt[a[i]];
		}
	}
}

signed main() {
    sync;
	F(i, 0, D)if(is_good(i))nums.pb(i);
	I(x, nums)G[x] = 1;
	cin >> n >> q;
	F(i, 0, n)
		cin >> a[i];
	build();
	F(i, 0, q){
		string s;
		cin >> s;
		if(s == "count"){
			int l, r;
			cin >> l >> r;
			--l; --r;
			cout << get(l, r) << '\n';
		}
		else{
			int l, r, x;
			cin >> l >> r >> x;
			--l; --r;
			add(l, r, x);
		}
	}
	return 0;
}