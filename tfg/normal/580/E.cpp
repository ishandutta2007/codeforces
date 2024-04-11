#include <vector>
#include <iostream>
#include <cstdio>

typedef long long ll;

const int mp = 4;
const ll MOD[mp] = {int(1e9) + 9, int(1e9) + 7, int(1e9) + 9, int(1e9) + 7};
const ll primes[mp] = {23, 31, 47, 53};

int c;

struct node
{
	node()
	{
		hash = base = 0;
		size = 1;
		lazy = -1;
	}

	node(int a) //init
	{
		hash = a - '0' + 1;
		base = 1;
		size = primes[c];
		lazy = -1;
	}

	node(node a, node b)
	{
		hash = ((ll) a.hash * b.size + b.hash) % MOD[c];
		size = (ll) a.size * b.size % MOD[c];
		base = ((ll) a.base * b.size + b.base) % MOD[c];
	}

	void add_lazy(char &a)
	{
		//adicionar lazy com contexto de lazy
		lazy = a - '0' + 1;
		hash = (ll) base * lazy % MOD[c];
	}

	void add_lazy(node &a)
	{
		//adicionar lazy do pai
		if(a.lazy != -1) {
			lazy = a.lazy;
			hash = (ll) base * lazy % MOD[c];
		}
	}

	void inc_lazy()
	{
		//incrementar com o lazy
		if(lazy != -1) {
			lazy = -1;
		}
	}
	//atributos
	int size;
	int base;
	int hash;

	//lazy
	int lazy;
};

template <class i_t, class s_t, class lazy_cont = int>
class Segment_Tree
{
public:
	Segment_Tree(std::vector<s_t> a)
	{
		n = a.size();
		st.resize(4*n);
		build(0, n - 1, 0, a);
	}

	i_t qry(int i, int j){return qry(0, n-1, i, j, 0);}
	void upd(int pos, s_t val){upd(0, n-1, pos, 0, val);}
	void upd(int i, int j, lazy_cont val){upd(0, n-1, i, j, 0, val);}
private:
	int left(int p){return p + p + 1;}
	int right(int p){return p + p + 2;}
	std::vector<s_t> a;
	std::vector<i_t> st;
	int n;

	void build(int l, int r, int ind, std::vector<s_t> &a)
	{
		if(l==r)
		{
			st[ind] = i_t(a[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, left(ind), a);
		build(mid + 1, r, right(ind), a);
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	void push(int l, int r, int ind)
	{
		if(!st[ind].lazy)
			return;
		if(l!=r)
		{
			st[left(ind)].add_lazy(st[ind]);
			st[right(ind)].add_lazy(st[ind]);
		}
		st[ind].inc_lazy();
	}

	void upd(int l, int r, int pos, int ind, s_t &val)
	{
		push(l, r, ind);
		
		if(l>pos || r<pos)
			return;

		if(l==r)
		{
			st[ind] = i_t(a[pos]);
			return;
		}

		int mid = (l + r) / 2;
		upd(l, mid, pos, left(ind), val);
		upd(mid + 1, r, pos, right(ind), val);
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	void upd(int l, int r, int i, int j, int ind, lazy_cont &val)
	{
		push(l, r, ind);
		
		if(r<i || l>j)
			return;

		if(l>=i && r<=j)
		{
			st[ind].add_lazy(val);
			push(l, r, ind);
		}
		else
		{
			int mid = (l + r) / 2;
			upd(l, mid, i, j, left(ind), val);
			upd(mid + 1, r, i, j, right(ind), val);
			st[ind] = i_t(st[left(ind)], st[right(ind)]);
		}
	}

	i_t qry(int l, int r, int i, int j, int ind)
	{
		int mid = (l + r) / 2;
		push(l, r, ind);

		if(r<i || l>j)
			return i_t();

		else if(l>=i && r<=j)
			return st[ind];

		return i_t(
			qry(l, mid, i, j, left(ind)),
			qry(mid + 1, r, i, j, right(ind))
				);
	}
};

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD[c];
		}
		x = x * x % MOD[c];
	}
	return ans;
}

char str[200200];

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	m += k;
	//std::string str;
	//std::cin >> str;
	scanf(" %s", str);
	std::vector<char> st_base(n, '0');
	for(int i = 0; i < n; i++) {
		st_base[i] = str[i];
	}
	std::vector<Segment_Tree<node, char, char>> segs;
	for(c = 0; c < mp; c++) {
		segs.emplace_back(Segment_Tree<node, char, char>(st_base));
	}
	while(m--) {
		int type, l, r, last;
		//std::cin >> type >> l >> r >> last;
		scanf("%i %i %i %i", &type, &l, &r, &last);
		l--;r--;
		if(type == 1) {
			// update
			for(c = 0; c < mp; c++) {
				segs[c].upd(l, r, last + '0');
			}
		} else {
			bool valid = true;
			if(last == r - l + 1) {
				//std::cout << "first case\n";
				valid = true;
			} else {
				if((r - l + 1) % last != 0) {
					int rest = (r - l + 1) % last;
					for(c = 0; c < mp && valid; c++) {
						if(segs[c].qry(r - rest + 1, r).hash != segs[c].qry(r - rest + 1 - last, r - last).hash) {
							valid = false;
						}
					}
					r -= rest;
				}
				//std::cout << "third case\n";
				int rep = (r - l + 1) / last;
				//std::cout << "rep is " << rep << '\n';
				for(c = 0; c < mp && valid && rep > 1; c++) {
					ll hash = segs[c].qry(l, l + last - 1).hash;
					//std::cout << "for (" << MOD[c] << ", " << primes[c] << ") got hash (" << hash << ")\n";
					//std::cout << "other is " << segs[c].qry(l + last, l + last + last - 1).hash << "\n";
					if(hash * ((fexp(primes[c], r - l + 1) - 1) * fexp(fexp(primes[c], last) - 1, MOD[c] - 2) % MOD[c]) % MOD[c] != segs[c].qry(l, r).hash) {
						//std::cout << "top is " << fexp(fexp(primes[c], last), rep) - 1 << ", bottom is " << fexp(primes[c] - 1, MOD[c] - 2) << '\n';
						valid = false;
					}
				}
			}
			if(valid) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		}
	}
}