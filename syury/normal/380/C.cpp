#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
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
#define fi0(x) memset(x, 0, sizeof(x))
#define y1 adjf

int n;
string s;

auto w = [](char c)->int{
	ret (c == '(') ? 1 : -1;
};

struct node{
	int val = 0;
	int uo = 0, uc = 0;
	node *l, *r;
};

node * build(int l, int r){
	node * v = new node;
	if(l == r){
		v->val = 0;
		if(w(s[l]) == 1){
			v->uo = 1;
		}
		else{v->uc = 1;}
		ret v;
	}
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	v->val = v->l->val + v->r->val;
	int d = min(v->r->uc, v->l->uo);
	v->val += d;
	v->uo = v->l->uo + v->r->uo - d;
	v->uc = v->l->uc + v->r->uc - d;
	ret v;
}

queue<node*>q;

void get(node * v, int l, int r, int ul, int ur){
    //printf("get %d %d %d %d\n", l, r, ul, ur); fflush(stdout);
	if(ul > ur)ret;
	if(l == ul && r == ur){q.push(v); ret;}
	int mid = (l + r) >> 1;
	get(v->l, l, mid, ul, min(ur, mid));
	get(v->r, mid + 1, r, max(ul, mid + 1), ur);
}

void cpy(node * dst, node * src){
	dst->val = src->val;
	dst->uo = src->uo;
	dst->uc = src->uc;
}

node * root;
node * tmp = new node, * tmr = new node;


int query(int l, int r){
	get(root, 0, n - 1, l, r);
	cpy(tmp, q.front());
	q.pop();
	while(!q.empty()){
		node * u = q.front();
		q.pop();
		tmr->val = tmp->val + u->val;
		int d = min(u->uc, tmp->uo);
		tmr->val += d;
		tmr->uo = tmp->uo + u->uo - d;
		tmr->uc = tmp->uc + u->uc - d;
		cpy(tmp, tmr);
	}
	ret tmp->val;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = (int)s.length();
	root = build(0, n - 1);
	int m;
	cin >> m;
	F(i, 0, m){
		int l, r;
		cin >> l >> r;
		l--; r--;
		//printf("%d %d\n", l, r);
		printf("%d\n", 2 * query(l, r));
	}
	ret 0;
}