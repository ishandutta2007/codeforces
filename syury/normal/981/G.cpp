#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

const int maxn = 2e5 + 55;
const int mod = 998244353;
const int SZ = 450;

struct segment{
	int l, r;
	bool is;
	bool operator < (const segment & s)const{return l < s.l;}
};

ll kekus[maxn];
struct block{
	int l, r;
	ll k = 1, c = 0;
	ll sum = 0;
	void push(){
	    if(k == 1){
	       F(i, l, r){
		        kekus[i] = kekus[i] + c;
		        kekus[i] -= kekus[i] >= mod ? mod : 0;
		    }
		    k = 1; c = 0;
		    return;
	    }
		F(i, l, r){
		    kekus[i] = kekus[i] * k + c;
		    kekus[i] %= mod;
		}
		k = 1; c = 0;
	}
	bool has(int i){
		return l <= i && i < r;
	}
};

int n, q;
set<segment> s[maxn];
block b[maxn];
int bp = 0;

inline void add(int l, int r){
	for(int id = 0; id < bp && b[id].l <= r; id++){
		if(l <= b[id].l && b[id].r - 1 <= r){
			b[id].sum += b[id].r - b[id].l;
			b[id].sum -= b[id].sum >= mod ? mod : 0;
			b[id].c++;
			b[id].c -= b[id].c >= mod ? mod : 0;
			continue;
		}
		if(b[id].has(l) || b[id].has(r)){
			//b[id].sum %= mod;
			b[id].push();
			F(i, max(b[id].l, l), min(b[id].r, r + 1)){
				++kekus[i];
				kekus[i] -= kekus[i] >= mod ? mod : 0;
				++b[id].sum;
				b[id].sum -= b[id].sum >= mod ? mod : 0;
			}
		}
	}
}

inline void mul(int l, int r){
	for(int id = 0; id < bp && b[id].l <= r; id++){
		if(l <= b[id].l && b[id].r - 1 <= r){
			b[id].sum *= 2;
			b[id].sum -= b[id].sum >= mod ? mod : 0;
			b[id].c *= 2;
			b[id].k *= 2;
			b[id].c -= b[id].c >= mod ? mod : 0;
			b[id].k -= b[id].k >= mod ? mod : 0;
			continue;
		}
		if(b[id].has(l) || b[id].has(r)){
			//b[id].sum %= mod;
			b[id].push();
			F(i, max(b[id].l, l), min(b[id].r, r + 1)){
				b[id].sum += kekus[i];
				kekus[i] *= 2;
				kekus[i] -= kekus[i] >= mod ? mod : 0;
				b[id].sum -= b[id].sum >= mod ? mod : 0;
			}
		}
	}
}

inline ll get(int l, int r){
	ll ans = 0;
	for(int id = 0; id < bp && b[id].l <= r; id++){
		if(l <= b[id].l && b[id].r - 1 <= r){
			ans += b[id].sum;
			continue;
		}
		if(b[id].has(l) || b[id].has(r)){
			//b[id].sum %= mod;
			b[id].push();
			F(i, max(b[id].l, l), min(b[id].r, r + 1)){
				ans += kekus[i];
			}
		}
	}
	return ans%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	//n = q = 200000;
	F(i, 1, n + 1){
		s[i].insert({0, n - 1, false});
	}
	for(int i = 0; i < n; i += SZ){
		b[bp].l = i;
		b[bp].r = min(n, i + SZ);
		++bp;
	}
	F(i, 0, q){
		int tp, l, r;
		cin >> tp >> l >> r;
		//l = 1; r = rand()%n + 1;
		//if(l > r)swap(l, r);
		//tp = rand()%2 + 1;
		--l; --r;
		if(tp == 1){
			int x;
			cin >> x;
			//x = rand()%n + 1;
			auto it = s[x].upper_bound({l, l, 0});
			--it;
			if(l != it->l){
				segment ls{it->l, l - 1, it->is}, rs{l, it->r, it->is};
				s[x].erase(it);
				s[x].insert(ls);
				s[x].insert(rs);
			}
			it = s[x].upper_bound({r, r, 0});
			--it;
			if(r != it->r){
				segment ls{it->l, r, it->is}, rs{r + 1, it->r, it->is};
				s[x].erase(it);
				s[x].insert(ls);
				s[x].insert(rs);
			}
			while(true){
				it = s[x].lower_bound({l, l, 0});
				if(it == s[x].end() || it->l > r)break;
				if(it->is)mul(it->l, it->r);
				else add(it->l, it->r);
				s[x].erase(it);
			}
			s[x].insert({l, r, true});
		}
		else{
			cout << get(l, r) << '\n';
		}
	}
	return 0;
}