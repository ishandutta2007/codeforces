#include<bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

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
#define finf(x) memset(x, 127, sizeof(x))
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e6 + 6;

struct state{
	state* link = NULL;
	int len;
	map<char, state*> nxt;
	int cnt = 0;
	state(){nxt.clear();}
};

state* st[2 * MAXN];
int t;
int sz;
state* last;

void init(){
	sz = 1;
	st[0]->link = NULL;
	st[0]->len = 0;
	st[0]->nxt.clear();
	st[0]->cnt = 0;
	last = st[0];
}

void extend(char c){
	state* curr = st[sz++];
	curr->nxt.clear();
	curr->link = NULL;
	curr->cnt = 1;
	curr->len = last->len + 1;
	state* p = last;
	for(; p != NULL && !p->nxt.count(c); p = p->link)p->nxt[c] = curr;
	if(p == NULL){
		curr->link = st[0];
	}
	else{
		state* q = p->nxt[c];
		if(q->len == p->len + 1){
			curr->link = q;
		}
		else{
			state* clone = st[sz++];
			clone->len = p->len + 1;
			clone->nxt.clear();
			clone->cnt = 0;
			clone->nxt = q->nxt;
			clone->link = q->link;
			for(; p != NULL && p->nxt[c] == q; p = p->link)p->nxt[c] = clone;
			q->link = curr->link = clone;
		}
	}
	last = curr;
}

auto comp = [=](state* a, state* b){
	ret a->len > b->len;
};

char s[MAXN];
int n;
lint ans = 0ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	F(i, 0, 2 * MAXN)st[i] = new state;
	scanf("%d", &t);
	F(g, 0, t){
		n = 0;
		char c = getc(stdin);
		while(!isalpha(c))c = getc(stdin);
		while(isalpha(c)){
			s[n++] = c;
			c = getc(stdin);
		}
		init();
		F(i, 0, n)extend(s[i]);
		sort(st, st + sz, comp);
		F(i, 0, sz){
			if(st[i]->link != NULL)st[i]->link->cnt += st[i]->cnt;
		}
		ans = 0;
		F(i, 0, sz){
			if(st[i]->link != NULL)ans += (st[i]->len - st[i]->link->len) * 1ll * st[i]->cnt * 1ll * st[i]->cnt;
		}
		printf("%lld\n", ans);
	}
	ret 0;
}