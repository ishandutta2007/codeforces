#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <map>
#include <stack>
using namespace std;

const int MOD = 1000000007;
int powten[400005];

template <typename Func, int B>
struct stree
{
	int n;
	vector<int> nodes;
	Func op;
	explicit stree(int n_)
	{
		for (n = 1; n <= n_; n *= 2);
		nodes.resize(n * 2 + 1, B);
	}
	void update(int pos, int val)
	{
		val %= MOD;
		pos += n;
		nodes[pos] = val;
		while (pos >>= 1)
		{
			nodes[pos] = op(nodes[pos << 1], nodes[pos << 1 | 1]) % MOD;
		}
	}
	int get(int s, int e)
	{
		if (e >= n) e = n - 1;
		int ret = B;
		s += n; e += n;
		while (s <= e)
		{
			if (s & 1) ret = op(ret, nodes[s++]) % MOD;
			if ((e & 1) == 0) ret = op(ret, nodes[e--]) % MOD;
			s >>= 1; e >>= 1;
		}
		return ret;
	}
};

using sumtree = stree<plus<int>, 0>;
using multree = stree<multiplies<long long>, 1>;

struct numtree
{
	int n, l, mulidx, chidx;
	bool single = false;
	vector<pair<int, int>> nodes;
	explicit numtree(int n_, int mulidx, int chidx, int l)
		: l(l), mulidx(mulidx), chidx(chidx)
	{
		for (n = 1; n <= n_; n *= 2);
		nodes.resize(n * 2 + 1);
	}
	pair<int, int> merge(pair<int, int> p1, pair<int, int> p2)
	{
		return{
			(p1.first * (long long)powten[p2.second] + p2.first) % MOD,
			p1.second + p2.second
		};
	}
	void update(int pos, int val)
	{
		pos += n;
		nodes[pos] = { val, 1 };
		while (pos >>= 1)
		{
			nodes[pos] = merge(nodes[pos << 1], nodes[pos << 1 | 1]);
		}
	}
	int get(int s, int e)
	{
		if (e >= n) e = n - 1;
		pair<int, int> left = { 0, 0 }, right = { 0, 0 };
		s += n; e += n;
		while (s <= e)
		{
			if (s & 1) left = merge(left, nodes[s++]);
			if ((e & 1) == 0) right = merge(nodes[e--], right);
			s >>= 1; e >>= 1;
		}
		return merge(left, right).first;
	}
};

struct paren
{
	int l, r;
	vector<paren *> childs;
	vector<int> queries;
};

pair<int, int> query[400005];
char dat[400005];
paren *pid[400005];
int len;
int ans[400005];
paren root;

void parse_paren()
{
	stack<paren *> stk;
	stk.push(&root);
	for (int i = 1; i < len - 1; i++)
	{
		pid[i] = stk.top();
		if (dat[i] == '(')
		{
			stk.top()->childs.push_back(new paren{});
			auto p = stk.top()->childs.back();
			p->l = i;
			stk.push(p);
		}
		else if (dat[i] == ')')
		{
			stk.top()->r = i;
			stk.pop();
			pid[i] = stk.top();
		}
	}
}

inline bool isop(char ch)
{
	return ch == '*' || ch == '+';
}

int dfs(paren *node)
{
	vector<int> cval;
	auto &&chd = node->childs;
	for (auto &&p : chd) cval.push_back(dfs(p));

	map<pair<int, int>, numtree *> mp;
	vector<multree> multrees;
	vector<numtree *> numtrees;

	int cidx = 0;
	for (int i = node->l + 1; i <= node->r; i++)
	{
		if (i == node->r || dat[i] == '+')
		{
			// flush multree
			int midx = multrees.size();
			multrees.emplace_back(numtrees.size());
			for (int j = 0; j < numtrees.size(); j++)
			{
				numtrees[j]->mulidx = midx;
				numtrees[j]->chidx = j;
				multrees.back().update(j, numtrees[j]->nodes[1].first);
			}
			numtrees.clear();
		}
		else if (cidx < chd.size() && chd[cidx]->l == i)
		{
			numtrees.emplace_back(new numtree(1, 0, 0, i));
			numtrees.back()->single = true;
			numtrees.back()->update(0, cval[cidx]);
			mp[make_pair(i, chd[cidx]->r)] = numtrees.back();
			i = chd[cidx]->r;
			cidx++;
			continue;
		}
		else if (dat[i] >= '0' && dat[i] <= '9')
		{
			int j;
			for (j = i + 1; j <= node->r - 1 && dat[j] >= '0' && dat[j] <= '9'; j++);
			j--;
			numtrees.emplace_back(new numtree(j - i + 1, 0, 0, i));
			mp[make_pair(i, j)] = numtrees.back();
			while (i <= j)
			{
				numtrees.back()->update(i - numtrees.back()->l, dat[i] - '0');
				i++;
			}
			i--;
		}
	}

	sumtree sumt(multrees.size());
	for (int i = 0; i < multrees.size(); i++)
	{
		sumt.update(i, multrees[i].nodes[1]);
	}

	for (int q : node->queries)
	{
		int l = query[q].first, r = query[q].second;
		auto &&itr1 = mp.lower_bound(make_pair(l, 0));
		if (itr1 == mp.end() || itr1->first.first > l)
		{
			--itr1;
		}

		auto &&itr2 = mp.lower_bound(make_pair(r, 0));
		if (itr2 == mp.end() || itr2->first.first > r)
		{
			--itr2;
		}

		if (itr1 == itr2)
		{
			ans[q] = itr1->second->get(l - itr1->second->l, r - itr1->second->l);
		}
		else
		{
			int midx1 = itr1->second->mulidx;
			int midx2 = itr2->second->mulidx;

			int org11 = multrees[midx1].get(itr1->second->chidx, itr1->second->chidx);
			int org12 = multrees[midx2].get(itr2->second->chidx, itr2->second->chidx);

			if (itr1->second->single == false) multrees[midx1].update(itr1->second->chidx, itr1->second->get(l - itr1->second->l, itr1->second->n - 1));
			if (itr2->second->single == false) multrees[midx2].update(itr2->second->chidx, itr2->second->get(0, r - itr2->second->l));

			if (midx1 == midx2)
			{
				ans[q] = multrees[midx1].get(itr1->second->chidx, itr2->second->chidx);
			}
			else
			{
				int org1 = sumt.get(midx1, midx1);
				int org2 = sumt.get(midx2, midx2);

				sumt.update(midx1, multrees[midx1].get(itr1->second->chidx, multrees[midx1].n - 1));
				sumt.update(midx2, multrees[midx2].get(0, itr2->second->chidx));

				ans[q] = sumt.get(midx1, midx2);

				sumt.update(midx1, org1);
				sumt.update(midx2, org2);
			}

			multrees[midx1].update(itr1->second->chidx, org11);
			multrees[midx2].update(itr2->second->chidx, org12);
		}
	}

	for (auto &&e : mp) delete e.second;

	return sumt.nodes[1];
}

int main()
{
	powten[0] = 1;
	for (int i = 1; i <= 400000; i++) powten[i] = (long long)powten[i - 1] * 10 % MOD;

	dat[0] = '(';
	scanf("%s", dat + 1);
	len = strlen(dat);
	dat[len++] = ')';

	root.l = 0; root.r = len - 1;
	pid[0] = pid[len - 1] = &root;

	parse_paren();

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &query[i].first, &query[i].second);
		if (pid[query[i].first] == nullptr || pid[query[i].first] != pid[query[i].second] ||
			isop(dat[query[i].first]) || isop(dat[query[i].second]) ||
			dat[query[i].first] == ')' ||
			dat[query[i].second] == '(')
		{
			ans[i] = -1;
		}
		else
		{
			pid[query[i].first]->queries.push_back(i);
		}
	}

	dfs(&root);

	for (int i = 0; i < q; i++)
	{
		printf("%d\n", ans[i]);
	}
}