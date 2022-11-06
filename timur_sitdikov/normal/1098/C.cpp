#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

int p[MAXN];
int deg[MAXN];
int h[MAXN];

map<int, set<int> > leafs;
map<int, set<int> > vertices;
int n;
int top;

queue<int> qq;

void fill(int s, int st, int n) {
	qq.push(s);
	while(!qq.empty()) {
		s = qq.front();
		qq.pop();
		int lst_top = top;
		REP(i, 0, st) {
			if (top > n) {
				break;
			}
			deg[s]++;
			qq.push(top);
			h[top] = h[s] + 1;
			p[top++] = s;
		}
		int new_top = top;
		vertices[h[s]].insert(s);
		if (new_top == lst_top) {
			leafs[h[s]].insert(s);
		}
	}
}

ll dif;

void change(int leaf, int par) {
	
	/*printf("BEFORE\n");
	REPN(i, 2, n) {
		printf("%d ", p[i]);
	}
	printf("\nDif: %lld\n", dif);
	printf("leaf %d from %d to %d\n", leaf, p[leaf], par);*/
	
	int h_leaf = h[leaf];
	int h_par = h[par];
	dif -= h_par + 1 - h_leaf;
	leafs[h_leaf].erase(leaf);
	vertices[h_leaf].erase(leaf);
	h_leaf = h_par + 1;
	h[leaf] = h_leaf;
	leafs[h_leaf].insert(leaf);
	vertices[h_leaf].insert(leaf);
	if (deg[par] == 0) {
		leafs[h_par].erase(par);
	}
	deg[par]++;
	int from = p[leaf];
	p[leaf] = par;
	deg[from]--;
	if (deg[from] == 0) {
		leafs[h[from]].insert(from);
	}
	
	/*printf("AFTER\n");
	REPN(i, 2, n) {
		printf("%d ", p[i]);
	}
	printf("\nDif: %lld\n", dif);*/
}

void solve(){
	ll k;
	cin >> n >> k;
	if (k < 2 * n - 1 || k > (ll)n * (ll)(n + 1) / 2) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	if (k == (ll)n * (ll)(n + 1) / 2) {
		REP(i, 1, n) {
			printf("%d ", i);
		}
		putchar('\n');
		return;
	}
	int sz = 2;
	for(; ; sz++) {
		ll last = 0, cur = 1, sum = 0;
		for(int i = 1; ; i++) {
			if (last >= n) {
				break;
			}
			ll new_layer_sz = min(cur, n - last);
			sum += new_layer_sz * i;
			last += new_layer_sz;
			cur *= sz;
		}
		if (sum <= k) {
			dif = k - sum;
			break;
		}
	}
	h[1] = 1;
	top = 2;
	fill(1, sz, n);
	while(dif > 0) {
		while(leafs.begin()->_2.empty()) {
			leafs.erase(leafs.begin());
		}
		int cur_h = leafs.begin()->_1;
		int leaf = *leafs[cur_h].begin();
		int par_h = vertices.rbegin()->_1;
		int par = -1;
		if (par_h + 1 - cur_h > dif) {
			par_h = dif + cur_h - 1;
		}
		
		if (cur_h == par_h) {
			FA(it, vertices[par_h]) {
				if (*it != leaf && deg[*it] < sz) {
					par = *it;
					break;
				}
			}
			if (par == -1) {
				// actually corner case when dif == 1 
				assert(dif == 1);
				FA(it, vertices) {
					bool leaf_found = false;
					bool vertex_found = false;
					FA(it1, it->_2) {
						if (!leaf_found && deg[*it1] == 0) {
							leaf_found = true;
							leaf = *it1;
						} else if (!vertex_found && deg[*it1] < sz) {
							vertex_found = true;
							par = *it1;
						}
					}
					if (leaf_found && vertex_found) {
						break;
					}
				}
			}
		} else {
			par = *vertices[par_h].begin();
		}
		
		change(leaf, par);
	}
	
	REPN(i, 2, n) {
		printf("%d ", p[i]);
	}
	putchar('\n');
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}