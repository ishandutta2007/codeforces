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

const int maxn = 1e4 + 4;

bitset<maxn> t[4 * maxn];
vector<int> add[4 * maxn];
int out[maxn];
int op = 0;
int n, q;

void add_segment(int v, int l, int r, int ul, int ur, int x){
	if(ul > ur)return;
	if(l == ul && r == ur){
		add[v].push_back(x);
		return;
	}
	int mid = (l + r)/2;
	add_segment(2*v, l, mid, ul, min(ur, mid), x);
	add_segment(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, x);
}

void solve(int v, int l, int r){
	t[v].set(0);
	if(l != r){
		int mid = (l + r)/2;
		solve(2*v, l, mid);
		solve(2*v + 1, mid + 1, r);
		t[v] = t[2*v] | t[2*v + 1];
	}
	I(x, add[v]){
		t[v] |= t[v]<<x;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	F(i, 0, q){
		int l, r, x;
		cin >> l >> r >> x;
		--l; --r;
		add_segment(1, 0, n - 1, l, r, x);
	}
	solve(1, 0, n - 1);
	F(i, 1, n + 1){
		if(t[1].test(i))out[op++] = i;
	}
	cout << op << '\n';
	F(i, 0, op)cout << out[i] << ' ';
	return 0;
}