#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
struct FT {
	vector<ll> s;
	FT(int n) : s(n,0) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	void add(int l,int r,ll dif){
		update(l,dif);
		update(r,-dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};
int p1[1000009],p2[1000009],a1[1000009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int w;cin>>w;
	FT T(w+7);
	rep(i,n){
		int x;cin>>x;
		p1[0] = -1e9+7;
		p2[x+1] = p1[0];
		repA(j,1,x){
			cin>>p1[j];
			a1[j]=p1[j];
			p2[j] = p1[j];
			p1[j] = max(p1[j],p1[j-1]);
		}
		repD(j,x,1){
			p2[j]  = max(p2[j],p2[j+1]);
		}
		if(w>=2*x){
			T.add(x+1,w-x+1,max(p1[x],0));
			repA(j,1,x){
				T.add(j,j+1,max(p1[j],0));
			}
			repA(j,1,x){
				T.add(w-x+j,w-x+j+1,max(p2[j],0));	
			}
		}
		else{
			deque<pii> stk;
			repA(j,1,w-x+1){
				while(sz(stk)&&stk.back().fst<=a1[j]) stk.pop_back();
				stk.pb({a1[j],j});
				int cur = stk.front().fst;
				if(j<w-x+1||j>x) cur = max(cur,0);
				T.add(j,j+1,cur);
			}
			repA(j,w-x+2,x){
				while(sz(stk)&&stk.back().fst<=a1[j]) stk.pop_back();
				while(sz(stk)&&stk.front().snd<=j-(w-x+1)) stk.pop_front();
				stk.pb({a1[j],j});
				int cur = stk.front().fst;
				if(j<w-x+1||j>x) cur = max(cur,0);
				T.add(j,j+1,cur);
			}
			repA(j,x+1,w){
				int cur = p2[j-w+x];
				if(j<w-x+1||j>x) cur = max(cur,0);
				T.add(j,j+1,cur);
			}
		}
	}
	repA(i,1,w){
		cout<<T.query(i+1)<<' ';
	}
	return 0;
}