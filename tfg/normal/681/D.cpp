#include <iostream>
#include <vector>
#include <set>
#include <utility>

struct node
{
	node(){valid = false;}

	node(int a) //init
	{
		valid = true;
		ans = a;
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
			//merge
			ans = std::min(a.ans, b.ans);
		}
	}
	//atributos
	bool valid;
	int ans;
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

const int ms = 100100;

int size = 0;
int in[ms], out[ms], a[ms], h[ms];
bool visit[ms], up[ms];
std::vector<int> edges[ms];
int origin[ms];

typedef std::pair<int, int> ii;

void dfs(int on, int dist = 0)
{
	//std::cout << "on " << on << ", dist is " << dist << '\n';
	visit[on] = true;
	h[on] = dist;
	in[on] = size;
	for(int i = 0; i < edges[on].size(); i++)
		dfs(edges[on][i], dist + 1);
	origin[size] = on;
	out[on] = size++;
}

int main()
{
	int n, m;
	while(std::cin >> n >> m)
	{
		for(int i = 0; i < n; i++)
		{
			visit[i] = false;
			up[i] = false;
			edges[i].clear();
		}
		size = 0;
		for(int i = 0; i < m; i++)
		{
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			up[v] = true;
			edges[u].push_back(v);
		}
		for(int i = 0; i < n; i++)
		{
			std::cin >> a[i];
			a[i]--;
		}
		for(int i = 0; i < n; i++)
		{
			if(!up[i])
				dfs(i);
		}
		std::vector<int> vals;
		for(int i = 0; i < n; i++)
		{
			vals.push_back(h[a[origin[i]]]);
			//std::cout << i + 1 << " from " << origin[i] << " wants " << vals.back() << '\n';;
		}
		Segment_Tree<node, int, int> tree(vals);
		bool valid = true;
		for(int i = 0; i < n && valid; i++)
		{
			int cur_ans;
			if(in[i] == out[i])
				cur_ans = tree.qry(in[i], out[i]).ans;
			else
				cur_ans = tree.qry(in[i], out[i] - 1).ans;
			//std::cout << "on " << i + 1 << " got " << cur_ans << ", (" << in[i] << ", " << out[i] << ")\n";
			if(cur_ans < h[a[i]] || (cur_ans <= h[i] && cur_ans != h[a[i]]))
				valid = false;
		}
		if(valid)
		{
			std::vector<int> ans;
			std::set<ii> nums;
			for(int i = 0; i < n; i++)
				nums.insert(ii(-h[a[i]], a[i] + 1));
			for(std::set<ii>::iterator it = nums.begin(); it != nums.end(); it++)
				ans.push_back(it->second);
			std::cout << ans.size() << '\n';
			for(int i = 0; i < ans.size(); i++)
				std::cout << ans[i] << '\n';
		}
		else
			std::cout << "-1\n";
	}
}