#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Node{
	int l, r;
	PII v;
	Node (){}
	Node(int a, int b, PII c) : l(a), r(b), v(c) {}
};

int n, d, fre;
Node t[60*100000];
std::vector<ll> A;

PII max(ll a, ll b, int v=0, ll lo=0, ll hi=(1ll<<51)-1ll){
	if(a>b || v == -1) return MP(0, -1);
	if(a == lo && b == hi){
		return t[v].v;
	}
	ll mid = (lo+hi)/2;
	return std::max(max(a, std::min(b, mid), t[v].l, lo, mid),
					max(std::max(a, mid+1), b, t[v].r, mid+1, hi));
}

void set(ll a, PII val, int v=0, ll lo=0, ll hi=(1ll<<51)-1ll){
	if(lo == hi) t[v].v = std::max(t[v].v, val);
	else{
		ll mid = (lo+hi)/2;
		if(a > mid){
			if(t[v].r == -1) t[fre] = Node(-1, -1, MP(0, -1)), t[v].r = fre++;
			set(a, val, t[v].r, mid+1, hi);
			t[v].v = std::max(t[v].v, t[t[v].r].v);
		}else{
			if(t[v].l == -1) t[fre] = Node(-1, -1, MP(0, -1)), t[v].l = fre++;
			set(a, val, t[v].l, lo, mid);
			t[v].v = std::max(t[v].v, t[t[v].l].v);
		}
	}
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> d;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	t[fre++] = Node(-1, -1, MP(0, -1));
	VI parent(n);
	FOR(i, n){
		ll l = std::max(0ll, A[i]-d);
		ll r = A[i]+d;
		PII mx = std::max(max(0, l), max(r, (1ll<<51)-1));
		set(A[i], MP(mx.X+1, i));
		parent[i] = mx.Y;
	}
	PII mx = max(0, (1ll<<51)-1);
	int pos = mx.Y;
	VI ans;
	while(pos != -1){
		ans.push_back(pos);
		pos = parent[pos];
	}
	std::cout << SZ(ans) << "\n";
	std::reverse(ans.begin(), ans.end());
	TRAV(i, ans) std::cout << i+1 << " ";
	return 0;
}