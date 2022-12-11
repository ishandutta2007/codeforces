#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
#include <cstring>
using namespace std;

/*
* build complete DFA and output link for pattern matching.
*
* Usage:
*
* add(id, begin, end, translation function): add word.
* build(): build DFA from added words.
* countMatch(...): example of pattern matching procedure.
*
* Example:
*
* string patterns[] = { "abcabc", "bc", "c" };
* string match = "abcabc";
* AhoCorasick ac(256);
* for (int i = 0; i < 3; i++) ac.add(i, patterns[i].begin(), patterns[i].end(), identity);
* ac.build();
* auto freq = ac.countMatch(match.begin(), match.end(), identity);
*/

int score[205];
constexpr long long oo = -1e18;

struct AhoCorasick
{
	const int alphabet;
	struct node {
		node() : back(0), output_link(0) {}
		explicit node(int alphabet) : next(alphabet), back(0), output_link(0) {}
		vector<int> next, report;
		int back;
		int output_link;
	};
	int maxid;
	vector<node> dfa;
	vector<int> weight;
	vector<vector<vector<long long>>> dp;
	vector<vector<vector<char>>> visit;
	AhoCorasick(int alphabet) : alphabet(alphabet), dfa(1, node(alphabet)), maxid(0) { }
	template<typename InIt, typename Fn> void add(int id, InIt first, InIt last, Fn func) {
		int cur = 0;
		for (; first != last; ++first) {
			auto s = func(*first);
			if (auto next = dfa[cur].next[s]) cur = next;
			else {
				cur = dfa[cur].next[s] = (int)dfa.size();
				dfa.emplace_back(alphabet);
			}
		}
		dfa[cur].report.push_back(id);
		maxid = max(maxid, id);
	}
	void build() {
		weight.resize(dfa.size(), -1);
		dp.resize(50, vector<vector<long long>>(dfa.size(), vector<long long>(dfa.size())));
		visit.resize(50, vector<vector<char>>(dfa.size(), vector<char>(dfa.size())));

		queue<int> q;
		vector<char> visit(dfa.size());
		visit[0] = 1;
		q.push(0);
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			dfa[cur].output_link = dfa[cur].back;
			if (dfa[dfa[cur].back].report.empty())
				dfa[cur].output_link = dfa[dfa[cur].back].output_link;
			for (int s = 0; s < alphabet; s++) {
				auto &next = dfa[cur].next[s];
				if (next == 0) next = dfa[dfa[cur].back].next[s];
				if (visit[next]) continue;
				if (cur) dfa[next].back = dfa[dfa[cur].back].next[s];
				visit[next] = 1;
				q.push(next);
			}
		}
	}
	int getweight(int node)
	{
		if (weight[node] == -1)
		{
			weight[node] = 0;

			for (int p = node; p; p = dfa[p].output_link)
				for (auto id : dfa[p].report)
					weight[node] += score[id];
		}

		return weight[node];
	}
	// dp[i][j][k]: 2^i , j k    
	// dp[i][j][k] = max(dp[i-1][j][x]+dp[i-1][x][k])
	long long D(int t, int j, int k)
	{
		if (!visit[t][j][k])
		{
			visit[t][j][k] = 1;
			dp[t][j][k] = oo;
			if (t == 0)
			{
				//    
				if (find(dfa[j].next.begin(), dfa[j].next.end(), k) != dfa[j].next.end())
				{
					dp[t][j][k] = getweight(k);
				}
			}
			else
			{
				for (int x = 0; x < dfa.size(); x++)
				{
					if (D(t - 1, j, x) == oo || D(t - 1, x, k) == oo) continue;
					dp[t][j][k] = max(dp[t][j][k], dp[t - 1][j][x] + dp[t - 1][x][k]);
				}
			}
		}
		return dp[t][j][k];
	}
};


int main()
{
	int n; long long l;
	scanf("%d%lld", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
	}

	AhoCorasick ac(26);
	for (int i = 0; i < n; i++)
	{
		char tmp[300];
		scanf("%s", tmp);
		ac.add(i, tmp, tmp + strlen(tmp), [](char ch) {return ch - 'a';});
	}
	ac.build();
	vector<long long> ans(ac.dfa.size(), oo);
	ans[0] = 0;
	vector<long long> ans2(ac.dfa.size());
	for (int i = 0; (1LL << i) <= l; i++)
	{
		if (!(l & (1LL << i))) continue;

		for (int j = 0; j < ac.dfa.size(); j++)
		{
			ans2[j] = oo;

			for (int k = 0; k < ac.dfa.size(); k++)
			{
				ans2[j] = max(ans2[j], ans[k] + ac.D(i, k, j));
			}
		}

		swap(ans, ans2);
	}
	printf("%lld", *max_element(ans.begin(), ans.end()));
}