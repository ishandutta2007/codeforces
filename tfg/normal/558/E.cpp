#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstring>

typedef std::pair<int, int> ii;

const int ms = 'z' - 'a' + 1;

struct node
{
	node(){valid = false;}

	node(int a, int pos)
	{ //init
		valid = true;
		memset(vals, 0, sizeof vals);
		elem = 1;
		vals[a] = 1;
		l = r = pos;
		lazy = 0;
		//std::cout << "created on pos " << pos << '\n';
	}

	node(node a, node b)
	{
		if(!a.valid)
			*this=b;
		else if(!b.valid)
			*this=a;
		else
		{
			valid = true;
			lazy = false;
			//merge
			for(int i = 0; i < ms; i++)
				vals[i] = a.vals[i] + b.vals[i];
			elem = a.elem + b.elem;
			l = std::min(a.l, b.l);
			r = std::max(a.r, b.r);
		}
	}

	void add_lazy(node &a)
	{
		//adicionar lazy do pai
		if(a.lazy)
		{
			lazy = a.lazy;
			for(int i = 0; i < ms; i++)
				vals[i] = a.vals[i];
			int rem;
			if(lazy == 1)
				rem = l - a.l;
			else
				rem = a.r - r;
			//std::cout << "rem is " << rem << '\n';
			for(int i = 0; i < ms; i++)
			{
				int use = std::min(vals[i], rem);
				rem -= use;
				vals[i] -= use;
			}
			//std::cout << "rem is " << rem << '\n';
			if(lazy == 1)
				rem = a.r - r;
			else
				rem = l - a.l;
			for(int i = ms - 1; i >= 0; i--)
			{
				int use = std::min(vals[i], rem);
				rem -= use;
				vals[i] -= use;
			}
			//std::cout << "parent is (" << a.l << ", " << a.r << ")\n";
			//std::cout << "updated (" << l << ", " << r << "), got: ";
			//for(int i = 0; i < ms; i++)
			//	std::cout << vals[i] << ' ';
			//std::cout << '\n';
		}
	}

	void inc_lazy()
	{
		//incrementar com o lazy
		//zerar
		lazy = false;
	}
	//atributos
	bool valid;
	int vals[ms];
	int elem, l, r;

	//lazy
	int lazy;
};

template <class i_t, class s_t, class lazy_cont = int>
class Segment_Tree
{
public:
	Segment_Tree(std::vector<s_t> _a)
	{
		a = _a;
		n = a.size();
		st.resize(4*n);
		build(0, n - 1, 0);
	}

	i_t qry(int i, int j){return qry(0, n-1, i, j, 0);}
	void upd(int i, int j, lazy_cont val){upd(0, n-1, i, j, 0, val);}
private:
	int left(int p){return p + p + 1;}
	int right(int p){return p + p + 2;}
	std::vector<s_t> a;
	std::vector<i_t> st;
	int n;

	void build(int l, int r, int ind)
	{
		if(l==r)
		{
			st[ind] = i_t(a[l], l);
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, left(ind));
		build(mid + 1, r, right(ind));
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
		//std::cout << "(" << l << ", " << r << ") = (" << st[ind].l << ", " << st[ind].r << ")\n";
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

	void upd(int l, int r, int i, int j, int ind, lazy_cont &val)
	{
		//std::cout << "on (" << l << ", " << r << ")\n";
		push(l, r, ind);
		
		if(r<i || l>j)
			return;

		if(l>=i && r<=j)
		{
			//std::cout << "updating (" << l << ", " << r << ")\n";
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

int main()
{
	int n, q;
	std::cin >> n >> q;
	std::string str;
	std::cin >> str;
	std::vector<int> a;
	for(int i = 0; i < n; i++)
		a.push_back(str[i] - 'a');
	Segment_Tree<node, int, node> tree(a);
	while(q--)
	{
		int l, r, v;
		std::cin >> l >> r >> v;
		l--;r--;
		node cont = tree.qry(l, r);
		//std::cout << "cont is (" << cont.l << ", " << cont.r << "): ";
		//for(int i = 0; i < ms; i++)
		//	std::cout << cont.vals[i] << ' ';
		//std::cout << '\n';
		if(v == 1)
			cont.lazy = 1;
		else
			cont.lazy = -1;
		tree.upd(l, r, cont);
		/*for(int i = 0; i < n; i++)
		{
			node cont = tree.qry(i, i);
			for(int i = 0; i < ms; i++)
			{
				if(cont.vals[i])
					std::cout << (char)('a' + i);
			}
		}
		std::cout << '\n';*/
	}
	for(int i = 0; i < n; i++)
	{
		node cont = tree.qry(i, i);
		for(int i = 0; i < ms; i++)
		{
			if(cont.vals[i])
				std::cout << (char)('a' + i);
		}
	}
	std::cout << '\n';
}