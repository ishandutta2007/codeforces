#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;
const ll SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

//segTree
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

struct segTree{
	vector<ll> tree;
	segTree(ll n){
		tree.assign(n * 4, 0);
	}
	
	void update(ll idx, ll ss, ll se, ll p, ll v){
		if(ss == se){
			tree[idx] += v;
		}
		else{
			ll mid = (ss + se) / 2;
			if(p <= mid) update(left(idx), ss, mid, p, v);
			else update(right(idx), mid + 1, se, p, v);
			tree[idx] = tree[left(idx)] + tree[right(idx)];
		}
	}
	
	ll query(ll idx, ll ss, ll se, ll qs, ll qe){
		if(ss > qe || se < qs) return 0;
		if(qs <= ss && se <= qe)
			return tree[idx]; 
		ll mid = (ss + se) / 2;
		return query(left(idx), ss, mid, qs, qe) + query(right(idx), mid + 1, se, qs, qe);
	}
	
	ll search(ll idx, ll ss, ll se, ll sum){
		if(ss == se) return ss;
		ll mid = (ss+se)/2;
		if(sum <= tree[left(idx)])return search(left(idx), ss, mid, sum);
		return search(right(idx), mid+1, se, sum-tree[left(idx)]);
	}
};


void test_case(){
	ll n, k, m;
	cin >> n >> k >> m;
	vector<tuple<ll, ll, ll, ll>> v; 
	for(ll i = 0; i < m; i++){
		ll l, r, c, p;
		cin >> l >> r >> c >> p;
		v.emplace_back(p, c, l, r);
	}
	sort(v.begin(), v.end());
	vector<tuple<ll, ll, ll>> event;
	for(ll i = 0; i < m; i++){
		event.emplace_back(get<2>(v[i]), 0, i);
		event.emplace_back(get<3>(v[i]), 1, i);
	}
	sort(event.begin(), event.end());
	segTree s1(m), s2(m);
	ll res = 0;
	ll pos = 0;
	for(ll i = 1; i <= n; i++){
		while(pos < 2*m && get<0>(event[pos]) == i && !get<1>(event[pos])){//add
			ll id = get<2>(event[pos]);
			s1.update(1, 0, m-1, id, get<1>(v[id]));
			s2.update(1, 0, m-1, id, get<0>(v[id]) *(ll) get<1>(v[id]));
			pos++;
		}
		if(s1.query(1, 0, m-1, 0, m-1) <=k){
			res += s2.query(1, 0, m-1, 0, m-1);
		}
		else{
			ll x = s1.search(1, 0, m-1, k);
			res += s2.query(1, 0, m-1, 0, x-1);
			ll rem = s1.query(1, 0, m-1, 0, x) - k;
			res += (get<1>(v[x]) - rem) * get<0>(v[x]);
		}
		while(pos < 2*m && get<0>(event[pos]) == i && get<1>(event[pos])){//rem
			ll id = get<2>(event[pos]);
			s1.update(1, 0, m-1, id, -get<1>(v[id]));
			s2.update(1, 0, m-1, id, -get<0>(v[id]) *(ll) get<1>(v[id]));
			pos++;
		}
	}
	cout << res << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	ll t = 1;
	//cin >> t;
	for(ll i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}