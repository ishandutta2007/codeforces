#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT
 
using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;
 
template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int mod = 998244353;
const int N = 500000;

mt19937 rng (0);

struct node {
	node* left;
	node* right;
	int val;
	int add;
	int key;
	node (int x, int y) {
		left = right = nullptr;
		val = x;
		key = y;
		add = 0;
	}
};

int n;
int m;
int f[N];
int rf[N];
int inv[N];
int r;
node* root;

int cnk (int n, int k) {
	if (n < 0 || k < 0 || k > n) re 0;
	re ((ll)f[n] * rf[k] % mod * rf[n - k]) % mod;
}

void push (node* cur) {
	if (cur->add == 0) re;
	cur->val += cur->add;
	if (cur->left) cur->left->add += cur->add;
	if (cur->right) cur->right->add += cur->add;
	cur->add = 0;
}

void split (node* cur, int x, node** left, node** right) {
	if (!cur) *left = *right = nullptr; else {
		push (cur);
		if (cur->val >= x) {
			split (cur->left, x, left, right);
			cur->left = *right;
			*right = cur;
		} else {
			split (cur->right, x, left, right);
			cur->right = *left;
			*left = cur;
		}
	}
}

node* merge (node* left, node* right) {
	if (!left) re right;
	if (!right) re left;
	push (left);
	push (right);
	if (left->key > right->key) {
		left->right = merge (left->right, right);
		re left;
	} else {
		right->left = merge (left, right->left);
		re right;
	}
}

node* erase (node* cur, int x) {
	if (!cur) re cur;
	push (cur);
	if (cur->val == x) cur = merge (cur->left, cur->right);
	else
	if (cur->val > x) cur->left = erase (cur->left, x); else cur->right = erase (cur->right, x);
	re cur;
}

void add (int x) {
	node* left;
	node* right;
	split (root, x, &left, &right);
	if (right) right->add++;
	node* now = new node (x, rng ());
	left = erase (left, x - 1);
	left = merge (left, now);
	root = merge (left, right);
}

int calc (node* cur) {
	if (!cur) re 0;
	re 1 + calc (cur->left) + calc (cur->right);
}

void out (node* cur, int add) {
	if (!cur) re;
	add += cur->add;
	out (cur->left, add);
	printf ("%d ", cur->val + add);
	out (cur->right, add);
}

int main () {
	f[0] = rf[0] = f[1] = rf[1] = inv[1] = 1;
	for (int i = 2; i < N; i++) {
		inv[i] = mod - (ll)(mod / i) * inv[mod % i] % mod;
		f[i] = ((ll)f[i - 1] * i) % mod;
		rf[i] = ((ll)rf[i - 1] * inv[i]) % mod;
	}
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		root = nullptr;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			add (b);
/*			printf ("add %d\n", b);
			out (root, 0);
			printf ("\n");*/
		}
		int cnt = calc (root);
//		printf ("%d\n", cnt);
		printf ("%d\n", cnk (2 * n - 1 - cnt, n));
	}
    re 0;
}