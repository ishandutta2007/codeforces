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
#define finf(x) memset(x, 127, sizeof(x))
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

struct block{
	list<int> seq;
	set<pair<int, int> > s;
	int sz = 0;
};

void i_set(set<pair<int, int> > & s, int v){
	auto it = s.lower_bound(mk(v, 0));
	if(it == s.end() || it->X != v)s.ins(mk(v, 1));
	else {
		int c = it->Y;
		s.era(it);
		s.ins(mk(v, c + 1));
	}
}

void e_set(set<pair<int, int> > & s, int v){
	auto it = s.lower_bound(mk(v, 0));
	if(it == s.end()){printf("FAIL AT E_SET\n"); exit(0);}
	int c = it->Y;
	s.era(it);
	if(c != 1)s.ins(mk(v, c - 1));
}

pair<block*, block*> split(block* b){
	int ls = b->sz/2;
	block* l = new block;
	block* r = new block;
	l->sz = ls; r->sz = b->sz - ls;
	while(ls != 0){
		l->seq.pb(*(b->seq.begin()));
		b->seq.pop_front();
		ls--;
	}
	r->seq = b->seq;
	I(v, l->seq)i_set(l->s, v);
	I(v, r->seq)i_set(r->s, v);
	ret mk(l, r);
}

int n;
vector<int> a;
list<block*> bb;
int m;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n);
	F(i, 0, n)scanf("%d", &a[i]);
	reverse(all(a));
	int bsz = (int)sqrt(n) + 1;
	bsz = min(bsz, n);
	block* curr = new block;
	F(i, 0, n){
		if(curr->sz == bsz){bb.pb(curr); curr = new block;}
		curr->sz++;
		curr->seq.pb(a[i]);
		i_set(curr->s, a[i]);
	}
	bb.pb(curr);
	scanf("%d", &m);
	int lans = 0;
	F(i, 0, m){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l = (l + lans - 1)%n + 1;
		r = (r + lans - 1)%n + 1;
		if(l > r)swap(l, r);
		l = n + 1 - l; r = n + 1 - r;
		l--; r--;
		swap(l, r);
		if(t == 1){
			if(l == r)cont;
			int cl = 0;
			auto wat = bb.end(), wat2 = bb.end();
			int ll, rl;
			F(it, bb.begin(), bb.end()){
				int cr = cl + (*it)->sz - 1;
				if(cl <= l && l <= cr){
					wat = it; ll = cl;
				}
				if(cl <= r && r <= cr){
					wat2 = it; rl = cl;
				}
				cl = cr + 1;
			}
			if(wat == wat2){
				cl = rl;
				auto cc = (*wat)->seq.begin();
				int el;
				while(cl != r){if(cl == l)el = *cc; cl++; cc++;}
				cc++;
				(*wat)->seq.ins(cc, el);
				cl = ll; cc = (*wat)->seq.begin();
				while(cl != l){cl++; cc++;}
				(*wat)->seq.era(cc);
			}
			else{
				cl = ll;
				auto cc = (*wat)->seq.begin();
				while(cl != l){cl++; cc++;}
				int el = *cc;
				e_set((*wat)->s, el);
				(*wat)->seq.era(cc);
				cl = rl;
				cc = (*wat2)->seq.begin();
				while(cl != r){cl++; cc++;}
				cc++;
				(*wat2)->seq.ins(cc, el);
				i_set((*wat2)->s, el);
				(*wat)->sz--; (*wat2)->sz++;
				bool ms = false;
				if((*wat2)->sz >= bsz + bsz)ms = true;
				if((*wat)->sz == 0)bb.era(wat);
				if(ms){
					cl = 0;
					F(it, bb.begin(), bb.end()){
						int cr = cl + (*it)->sz - 1;
						if(cl <= r - 1 && r - 1 <= cr){wat = it; brk;}
						cl = cr + 1;
					}
					pair<block*, block*> res = split(*wat);
					bb.ins(wat, res.Y);
					F(it, bb.begin(), bb.end())if(*it == res.Y){wat = it; brk;}
					bb.ins(wat, res.X);
					F(it, bb.begin(), bb.end())if(*it == res.Y){wat = it; brk;}
					wat++;
					bb.era(wat);
				}
			}
		}
		else{
			int k;
			scanf("%d", &k);
			k = (k + lans - 1)%n + 1;
			int cl = 0;
			int ans = 0;
			F(it, bb.begin(), bb.end()){
				int cr = cl + (*it)->sz - 1;
				if(l <= cr && cr <= r && cl >= l && cl <= r){
					auto jt = (*it)->s.lower_bound(mk(k, 0));
					if(jt != (*it)->s.end() && jt->X == k)ans += jt->Y;
					cl = cr + 1;
					cont;
				}
				if((cl <= l && l <= cr) || (cl <= r && r <= cr)){
					int j = cl;
					auto jt = (*it)->seq.begin();
					while(j <= cr){
						if(l <= j && j <= r && *jt == k)ans++;
						jt++; j++;
					}
				}
				cl = cr + 1;
			}
			lans = ans;
			printf("%d\n", ans); fflush(stdout);
		}
	}
	ret 0;
}