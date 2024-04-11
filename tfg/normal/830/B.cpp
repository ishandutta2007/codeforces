#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int INF = 1e9;

struct node
{
	node(){valid = false;}

	node(int a, int pos) //init
	{
		valid = true;
		val = ii(a, pos);
		if(a == INF)
			sum = 0;
		else
			sum = 1;
	}

	node(node a, node b)
	{
		if(!a.valid)
			*this = b;
		else if(!b.valid)
			*this = a;
		else if(!a.valid && !b.valid)
			*this = node();
		else
		{
			valid = true;
			//merge
			val = std::min(a.val, b.val);
			sum = a.sum + b.sum;
		}
	}
	//atributos
	bool valid;
	int sum;
	ii val;
};

template <class i_t, class s_t>
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
	void upd(int pos, s_t val){upd(0, n-1, pos, 0, val);}
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
	}

	void upd(int l, int r, int pos, int ind, s_t &val)
	{
		if(l>pos || r<pos)
			return;

		if(l==r)
		{
			a[pos] = val;
			st[ind] = i_t(a[pos], pos);
			return;
		}

		int mid = (l + r) / 2;
		upd(l, mid, pos, left(ind), val);
		upd(mid + 1, r, pos, right(ind), val);
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	i_t qry(int l, int r, int i, int j, int ind)
	{
		int mid = (l + r) / 2;

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
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%i", &a[i]);
	Segment_Tree<node, int> tree(a);
	long long ans = 0;
	int miss = n;
	while(tree.qry(0, n - 1).sum > 0)
	{
		int on = 0;
		while(on < n && miss > 0 && tree.qry(on, n - 1).val.first == tree.qry(0, n - 1).val.first)
		{
			int to = tree.qry(on, n - 1).val.second;
			ans += tree.qry(on, to).sum;
			tree.upd(to, INF);
			on = to + 1;
			miss--;
		}
		if(on < n)
			ans += tree.qry(on, n - 1).sum;
	}
	std::cout << ans << "\n";
}