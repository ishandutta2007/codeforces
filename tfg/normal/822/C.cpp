#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

typedef long long ll;
typedef std::pair<ll, ll> ii;

const ll INF = 3e9;
const int ms = 200200;

struct node
{
	node(){valid = false; min = INF;}

	node(ll a) //init
	{
		valid = true;
		min = a;
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
			min = std::min(a.min, b.min);
		}
	}

	//atributos
	bool valid;
	ll min;
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
			st[ind] = i_t(a[l]);
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
			st[ind] = i_t(a[pos]);
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

std::vector<ii> ticket[ms];
ll cur[ms];

int main()
{
	for(int i = 0; i < ms; i++)
		cur[i] = INF;
	int n, x;
	std::cin >> n >> x;
	for(int i = 0; i < n; i++)
	{
		int l, r, c;
		scanf("%i %i %i", &l, &r, &c);
		int dur = r - l + 1;
		ticket[dur].push_back(ii(l, c));
	}
	Segment_Tree<node, ll> tree(std::vector<ll> (ms, INF));
	ll ans = INF;
	for(int i = 0; i + i <= x; i++)
	{
		int to = x - i;
		for(int j = 0; j < ticket[to].size(); j++)
		{
			cur[ticket[to][j].first] = std::min(ticket[to][j].second, cur[ticket[to][j].first]);
			//std::cout << "including (" << ticket[to][j].first << ", " << ticket[to][j].first + to - 1 << ", " << ticket[to][j].second << ")\n";
			tree.upd(ticket[to][j].first, cur[ticket[to][j].first]);
		}
		for(int j = 0; j < ticket[i].size(); j++)
		{
			if(ticket[i][j].first - to >= 0)
			{
				ans = std::min(ans, ticket[i][j].second + tree.qry(0, ticket[i][j].first - to).min);
				//std::cout << tree.qry(0, ticket[i][j].first - to).min << '\n';
			}
			if(ticket[i][j].first + i < ms)
			{
				ans = std::min(ans, ticket[i][j].second + tree.qry(ticket[i][j].first + i, ms).min);
				//std::cout << tree.qry(ticket[i][j].first + i, ms).min << '\n';
			}
			//std::cout << "paired (" << ticket[i][j].first << ", " << ticket[i][j].first + i - 1 << ", " << ticket[i][j].second << ") got " << ans << "\n";
		}
		for(int j = 0; j < ticket[to].size(); j++)
		{
			cur[ticket[to][j].first] = INF;
			tree.upd(ticket[to][j].first, cur[ticket[to][j].first]);
		}
	}
	if(ans >= INF)
		ans = -1;
	std::cout << ans << '\n';
}