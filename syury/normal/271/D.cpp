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
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf

struct node{
	map<char, node*> nxt;
	node * link;
	int len;
};

node * root;
node * last;

void sa_init(){
	root = new node;
	root->link = NULL;
	root->len = 0;
	last = root;
}

void sa_extend(char c){
	node * v = new node;
	v->len = last->len + 1;
	node * p = last;
	for(; p != NULL && !p->nxt.count(c); p = p->link){
		p->nxt[c] = v;
	}
	if(p == NULL){
		v->link = root;
	}
	else{
		node * q = p->nxt[c];
		if(p->len + 1 == q->len){
			v->link = q;
		}
		else{
			node * clone = new node;
			clone->len = p->len + 1;
			clone->nxt = q->nxt;
			clone->link = q->link;
			for(; p != NULL && p->nxt[c] == q; p = p->link)
				p->nxt[c] = clone;
			q->link = v->link = clone;
		}
	}
	last = v;
}

void sa_build(string & s){
	sa_init();
	F(i, 0, (int)s.length()){
		sa_extend(s[i]);
	}
}

int bad['z' - 'a' + 1];
string s, ms;
int n, k;
int cnt = 0;
int ck = 0;

void dfs(node * v){
	if(ck <= k && v != root){cnt++;}
	F(it, v->nxt.begin(), v->nxt.end()){
		node * to = it->Y;
		if(!to){cont;}
		char c = it->X;
		ck += bad[c - 'a'];
		dfs(to);
		ck -= bad[c - 'a'];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> ms >> k;
	F(i, 0, (int)ms.length()){
		if(ms[i] == '0'){bad[i] = 1;}
		else{bad[i] = 0;}
	}
	n = s.length();
	sa_build(s);
	dfs(root);
	printf("%d", cnt);
	ret 0;
}