#include<bits/stdc++.h>

const int N = 800010;

struct edge{
    int v, n;
};

edge e[N];

int head[N], tot = 1;

inline void add_edge(int u, int v){
    e[++ tot] = {v, head[u]}, head[u]=tot;
    e[++ tot] = {u, head[v]}, head[v]=tot;
}

class Tarjan{
    private:
        int st[N], top;
        std::stack <int> stack;
    public:
        int dfn[N], low[N], cnt;
        bool cut[N], bridge[N];
        int bccno[N], bcc_cnt;
        std::vector <int> bcc[N];
        int ebccno[N], ebcc_cnt;
        std::vector <int> ebcc[N];
        inline void init(int n, int m){
            cnt = bcc_cnt = ebcc_cnt = 0;
            for (int i = 1; i <= n; ++ i) dfn[i] = cut[i] = bccno[i] = ebccno[i] = 0;
            for (int i = 1; i <= m; ++ i) bridge[i] = 0;
        }
        void dfs(int x, int p){
            low[x] = dfn[x] = ++cnt;
            stack.push(x);
            int ch = 0;
            for (int i = head[x], y; i; i = e[i].n){
                y = e[i].v;
                if (y == p) continue;
                if (!dfn[y]){
                    st[++ top] = i;
                    ++ ch, dfs(y, x);
                    low[x] = std::min(low[x], low[y]);
                    if (dfn[x] <= low[y]){
                        cut[x] = 1;
                        bcc[++ bcc_cnt].clear();
                        for(int j, u, v; ; ){
                            j = st[top --];
                            u = e[j ^ 1].v, v = e[j].v;
                            if (bccno[u] != bcc_cnt) bcc[bccno[u] = bcc_cnt].push_back(u);
                            if (bccno[v] != bcc_cnt) bcc[bccno[v] = bcc_cnt].push_back(v);
                            if (j == i)break;
                        }
                    }
                    if (dfn[x] < low[y]) bridge[i >> 1] = 1;
                }
                else if (dfn[y] < dfn[x]){
                    st[++ top]=i;
                    low[x] = std::min(low[x], dfn[y]);
                }
            }
            if (!p && ch == 1) cut[x] = 0;
            if (dfn[x] == low[x]){
                ebcc[++ ebcc_cnt].clear();
                ebccno[x] = ebcc_cnt;
                ebcc[ebcc_cnt].push_back(x);
                while(stack.top() != x){
                    ebccno[stack.top()] = ebcc_cnt;
                    ebcc[ebcc_cnt].push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
        }
};

Tarjan tar;

typedef long long ll;
typedef std::pair <int, int> pii;

pii p[N];
int right[N];
ll pre[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
	tar.init(n, m);
	for (int i = 1; i <= n; ++ i){
		if (!tar.dfn[i]){
			tar.dfs(i, 0);
		}
	}
	for (int i = 1; i <= tar.ebcc_cnt; ++ i){
		if (tar.ebcc[i].size() < 3) continue;
		std::sort(tar.ebcc[i].begin(), tar.ebcc[i].end());
		p[i - 1] = {*(tar.ebcc[i].begin()), *(-- tar.ebcc[i].end())};
	}
	std::sort(p, p + tar.ebcc_cnt, std::greater <pii>());
	int min = n + 1;
	for (int i = n, j = 0; i; -- i){
		while (j < tar.ebcc_cnt && p[j].first >= i){
			min = std::min(min, p[j].second);
			++ j;
		}
		right[i] = min - 1;
	}
	for (int i = 1; i <= n; ++ i){
		pre[i] = pre[i - 1] + right[i];
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int l, r;
		scanf("%d%d", &l, &r);
		int x = std::lower_bound(right + l, right + r + 1, r) - right;
		ll ans = pre[x - 1] - pre[l - 1] - 1ll * (l + x - 3) * (x - l) / 2;
		ans += 1ll * (r - x + 1) * (r - x + 2) >> 1;
		printf("%I64d\n", ans);
	}
	return 0;
}