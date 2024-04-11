#include <bits/stdc++.h>
using namespace std;

struct MaxFlowDinic
{
    struct edge
    {
        int e, inv, flow, idx;
    };

    int n;
    vector<vector<edge>> graph;
    vector<int> start, lv;

    void init(int n)
    {
        this->n = n;
        graph.clear();
        graph.resize(n);
        start.resize(n);
        lv.resize(n);
    }

    void add_edge(int s, int e, int idx, int cap, int caprev = 0)
    {
        graph[s].push_back({e, (int)graph[e].size(), cap, idx});
        graph[e].push_back({s, (int)graph[s].size() - 1, caprev, -1});
    }

    void assign_level(int s, int e)
    {
        queue<int> que;
        fill(start.begin(), start.end(), 0);
        fill(lv.begin(), lv.end(), 0);
        lv[s] = 1;
        que.push(s);

        while (que.empty() == false)
        {
            int t = que.front();
            que.pop();
            for (auto &nxt : graph[t])
            {
                if (nxt.flow == 0) continue;
                if (lv[nxt.e]) continue;

                lv[nxt.e] = lv[t] + 1;
                que.push(nxt.e);
            }
        }
    }

    int block_flow(int s, int e, int mx = INT_MAX)
    {
        if (s == e) return mx;

        for (int &i = start[s]; i < graph[s].size(); i++)
        {
            if (graph[s][i].flow == 0) continue;

            int nxt = graph[s][i].e;
            if (lv[nxt] != lv[s] + 1) continue;

            if (int ret = block_flow(nxt, e, min(mx, graph[s][i].flow)))
            {
                graph[s][i].flow -= ret;
                graph[nxt][graph[s][i].inv].flow += ret;
                return ret;
            }
        }

        return 0;
    }

    int solve(int s, int e)
    {
        int ret = 0;
        for (;;)
        {
            assign_level(s, e);
            if (lv[e] == 0) break;
            while (int f = block_flow(s, e)) ret += f;
        }
        return ret;
    }
};

struct MaxFlowEdgeDemands
{
	MaxFlowDinic mf;

	struct edge
	{
		int s, e, idx;
		int cap, demands;
	};

	vector<int> ind_total, outd_total;
	vector<edge> edges;
	int D;
	int n;

	void init(int _n)
	{
		n = _n;
		D = 0;
		edges.clear();
		mf.init(n + 2);
		ind_total.resize(n);
		outd_total.resize(n);
		fill(ind_total.begin(), ind_total.end(), 0);
		fill(outd_total.begin(), outd_total.end(), 0);
	}

	void add_edge(int s, int e, int idx, int cap, int demands = 0)
	{
		edges.push_back({ s, e, idx, cap, demands });
		D += demands;
		ind_total[e] += demands;
		outd_total[s] += demands;
	}

	pair<bool, int> solve(int s, int e)
	{
		for (auto &e : edges) mf.add_edge(e.s, e.e, e.idx, e.cap - e.demands);
		mf.add_edge(e, s, -1, numeric_limits<int>::max());

		for (int i = 0; i < n; i++)
		{
			if (ind_total[i]) mf.add_edge(n, i, -1, ind_total[i]);
			if (outd_total[i]) mf.add_edge(i, n + 1, -1, outd_total[i]);
		}

		auto ret = mf.solve(n, n + 1);
		if (ret != D) return{ false, 0 };

		for (int i = 0; i < n; i++)
		{
			if (ind_total[i]) mf.graph[i].pop_back();
			if (outd_total[i]) mf.graph[i].pop_back();
		}

		return{ true, mf.solve(s, e) };
	}
};

struct constraint
{
	int a, l, c;
};

int coord[100005][2];
vector<int> line[2];
int cnt[2][100005];
int minval[2][100005];
constraint cons[100005];
int ans[100005];

int main()
{
	int n, m, r, b;
	scanf("%d%d%d%d", &n, &m, &r, &b);

	fill(&minval[0][0], &minval[2][0], 1e9);

	for (int i = 0; i < n; i++) scanf("%d%d", &coord[i][0], &coord[i][1]);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		cons[i] = { a, b, c };
		line[a].push_back(b);
	}

	for (int i = 0; i < 2; i++)
	{
		sort(line[i].begin(), line[i].end());
		line[i].erase(unique(line[i].begin(), line[i].end()), line[i].end());
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int idx = lower_bound(line[j].begin(), line[j].end(), coord[i][j]) - line[j].begin();
			if (idx < line[j].size() && line[j][idx] == coord[i][j]) coord[i][j] = idx;
			else coord[i][j] = line[j].size();
			cnt[j][coord[i][j]]++;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int idx = lower_bound(line[cons[i].a].begin(), line[cons[i].a].end(), cons[i].l) - line[cons[i].a].begin();
		minval[cons[i].a][idx] = min(minval[cons[i].a][idx], cons[i].c);
	}

	MaxFlowEdgeDemands mf;
	mf.init(line[0].size() + line[1].size() + 4);
	int base1 = 1, base2 = base1 + line[0].size() + 1;
	int sink = line[0].size() + line[1].size() + 3;

	for (int i = 0; i < line[0].size(); i++)
	{
		if (cnt[0][i] % 2 == 1 && minval[0][i] == 0)
		{
			printf("-1\n"); return 0;
		}
		mf.add_edge(0, i + base1, -1, min(cnt[0][i], (cnt[0][i] + minval[0][i]) / 2), max(0, (cnt[0][i] - minval[0][i] + 1) / 2));
	}

	for (int i = 0; i < line[1].size(); i++)
	{
		if (cnt[1][i] % 2 == 1 && minval[1][i] == 0)
		{
			printf("-1\n"); return 0;
		}
		mf.add_edge(i + base2, sink, -1, min(cnt[1][i], (cnt[1][i] + minval[1][i]) / 2), max(0, (cnt[1][i] - minval[1][i] + 1) / 2));
	}

	mf.add_edge(0, base1 + line[0].size(), -1, n);
	mf.add_edge(base2 + line[1].size(), sink, -1, n);

	for (int i = 0; i < n; i++)
	{
		mf.add_edge(base1 + coord[i][0], base2 + coord[i][1], i, 1);
	}

	auto ret = mf.solve(0, sink);

	if (ret.first == false)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n", ret.second * 1ll * min(r, b) + (n - ret.second) * 1ll * max(r, b));

	char minc, maxc;

	if (r < b) minc = 'r', maxc = 'b';
	else minc = 'b', maxc = 'r';

	for (auto &vt : mf.mf.graph)
	{
		for (auto &e : vt)
		{
			if (e.idx != -1) ans[e.idx] = e.flow;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i]) putchar(maxc);
		else putchar(minc);
	}
	printf("\n");
}