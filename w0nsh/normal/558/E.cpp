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

struct Tree{
	int BOTTOM;
	VI t, u, s;
	void build(std::string &str, char ch){
		BOTTOM = 1;
		while(BOTTOM < SZ(str)) BOTTOM <<= 1;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2, -1);
		FOR(i, SZ(str)) if(str[i] == ch) t[BOTTOM+i] = 1;
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = t[i<<1]+t[(i<<1)+1];
		}
	}
	void upd(int v, int lo, int hi){
		if(u[v] != -1){
			if(v < BOTTOM) u[v<<1] = u[v], u[(v<<1)+1] = u[v];
			t[v] = (hi-lo+1)*u[v];
			u[v] = -1;
		}
	}
	void update(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a > b) return;
		if(a == lo && b == hi){
			u[v] = w;
			upd(v, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		update(a, std::min(b, mid), w, v<<1, lo, mid);
		update(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = t[v<<1]+t[(v<<1)+1];
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a > b) return 0;
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return query(a, std::min(b, mid), v<<1, lo, mid)
				+ query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
	}
	void flow(int v, int lo, int hi){
		upd(v, lo, hi);
		if(v < BOTTOM){
			int mid = (lo+hi)/2;
			flow(v<<1, lo, mid);
			flow((v<<1)+1, mid+1, hi);
		}
	}
	void get(std::string &str, char ch){
		flow(1, 0, BOTTOM-1);
		FOR(i, SZ(str)) if(t[i+BOTTOM] == 1) str[i] = ch;
	}
};

Tree tree[26];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	std::string str;
	std::cin >> str;
	FOR(i, 26) tree[i].build(str, 'a'+i);
	FOR(_, q){
		int a, b, k;
		std::cin >> a >> b >> k;
		a--;b--;
		VI pref(27);
		REP(i, 1, 27) pref[i] = tree[i-1].query(a, b), tree[i-1].update(a, b, 0);
		REP(i, 1, 27) pref[i] += pref[i-1];
		if(k == 1){
			FOR(i, 26){
				tree[i].update(a+pref[i], a+pref[i+1]-1, 1);
			}
		}else{
			FOR(i, 26){
				tree[i].update(b-pref[i+1]+1, b-pref[i], 1);
			}
		}
	}
	std::string ans;
	FOR(i, n) ans.push_back('?');
	FOR(i, 26){
		tree[i].get(ans, 'a'+i);
	}
	std::cout << ans << "\n";
	return 0;
}