#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define P pair
ll n, m, k;
const int mxN=1e6,M=998244353,mod=1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


typedef int T;
T op(T x, T y) {
	return max(x,y);
}

struct node {
	
	struct node *lChild, *rChild;
	int cnt;
	T val;
	int leftmost, rightmost;
	node(int left, int right) {
		cnt=1;
		leftmost=left;
		rightmost=right;
		if(leftmost==rightmost)
			val=0,lChild=nullptr, rChild=nullptr;
		else {
			int mid=(leftmost+rightmost)/2;
			lChild=new node(left,mid);
			rChild=new node(mid+1,right);
			recalc();
			cnt+=lChild->cnt+rChild->cnt;
		}
	}

	void recalc() {
		val=op(lChild->val,rChild->val);
	}
};	

void upd(node *root, int pos, T val) {
	if(root->leftmost==root->rightmost) {
		root->val=val;
	} else {
		if(root->lChild->rightmost >= pos)
			upd(root->lChild, pos, val);
		else
			upd(root->rChild, pos, val);
		root->recalc();
	}
}

T qry(node *root, int l, int r) {
	if(l > root->rightmost || r < root->leftmost)
		return 0;
	
	else if(l <= root->leftmost && r >= root->rightmost)
		return root->val;

	return op(qry(root->lChild, l, r), qry(root->rChild, l, r));
}
void solve(int test_case = 0) {
	int n; cin >> n;
	vi a(n);
	node *root = new node(0,n-1);
	rep(i,0,n)
		cin >> a[i];
	rep(i,0,n)
		rep(j,0,n)
			a[i]&=a[j];
	cout << *max_element(all(a)) << "\n";
}


int main()
{
    //setup();
	cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
     cin >> T;

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}