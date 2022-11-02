#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf
#define tm afhdhn

const int BITS = 30;
int n, m;
vector<int> a;
vector<vector<int> > add;
vector<pair<int, pair<int, int> > > q;
vector<int> pows;
int curr[BITS];
int allset = 0;

struct node{
	node *l, *r;
	int val;
};

node * build(int l, int r){
	node * v = new node;
	if(l == r){v->val = a[l]; ret v;}
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	v->val = v->l->val & v->r->val;
	ret v;
}

int get(node * v, int l, int r, int ul, int ur){
	if(ul > ur)
		ret allset;
	if(l == ul && r == ur)
		ret v->val;
	int mid = (l + r) >> 1;
	ret get(v->l, l, mid, ul, min(ur, mid)) & get(v->r, mid + 1, r, max(ul, mid + 1), ur);
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d%d", &n, &m);
	a.rs(n); add.rs(n); q.rs(m); pows.rs(BITS);
	F(i, 0, BITS){
		pows[i] = 1 << i;
		allset ^= pows[i];
	}
	F(i, 0, n){
		add[i].rs(BITS); add[i].asg(BITS, 0);
	}
	F(i, 0, m){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x); l--; r--;
		q[i] = mk(x, mk(l, r));
		F(j, 0, BITS){
			if(x&pows[j]){
				add[l][j]++;
				if(r < n - 1)
					add[r + 1][j]--;
			}
		}
	}
	memset(curr, 0, sizeof(curr));
	F(i, 0, n){
		F(j, 0, BITS){
			curr[j] += add[i][j];
			if(curr[j] > 0)
				a[i] += pows[j];
		}
	}
	node * root = build(0, n - 1);
	F(i, 0, m){
		int cr = get(root, 0, n - 1, q[i].Y.X, q[i].Y.Y);
		if(cr != q[i].X){printf("NO"); ret 0;}
	}
	printf("YES\n");
	F(i, 0, n)
		printf("%d ", a[i]);
	ret 0;
}