#include "bits/stdc++.h"
using namespace std;

char text[1200005];
int matched[1200005];
int n, k;

struct AhoCorasick
{
    const int alphabet;
    struct node {
        node() {}
        explicit node(int alphabet) : next(alphabet) {}
        vector<int> next, report;
        int back = 0, output_link = 0;
    };
    int maxid = 0;
    vector<node> dfa;
    explicit AhoCorasick(int alphabet) : alphabet(alphabet), dfa(1, node(
      alphabet)) { }
    template<typename InIt> void add(int id, InIt first) {
		int cur=0;
		for ( ; *first; ++first) {
			auto s = *first-'a';
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
        queue<int> q;
        vector<char> visit(dfa.size());
        visit[0] = 1;
        q.push(0);
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
			dfa[cur].output_link = dfa[cur].back;
			if (dfa[dfa[cur].back].report.empty())
				dfa[cur].output_link = dfa[dfa[cur].back].output_link;
			for (int s=0;s<alphabet;s++){
				auto &next = dfa[cur].next[s];
				if (next == 0) next = dfa[dfa[cur].back].next[s];
				if (visit[next]) continue;
				if (cur) dfa[next].back = dfa[dfa[cur].back].next[s];
				visit[next] = 1;
				q.push(next);
			}
		}
	}
	void countMatch() {
		int cur = 0;
		for (int i = 0; i < n * k + k - 1; i++) {
			cur = dfa[cur].next[text[i]-'a'];
			for (int p = cur; p; p = dfa[p].output_link)
				for (auto id : dfa[p].report)
					matched[i] = id;
		}
	}
};

char pattern[2000005];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",text);
	memmove(text+n*k,text,k-1);

	AhoCorasick ac(26);

	int g;
	scanf("%d",&g);
	for (int i = 1; i <= g; i++)
	{
		scanf("%s",pattern);
		ac.add(i, pattern);
	}

	ac.build();
	ac.countMatch();

	for (int i = k - 1; i < 2 * k - 1; i++)
	{
		unordered_set<int> st;
		vector<int> ans;
		for (int j = 0; j < n; j++)
		{
			if (matched[i + j * k] == 0) break;
			if (st.insert(matched[i + j * k]).second == false) break;
			ans.push_back(matched[i + j * k]);
		}
		if (ans.size() == n)
		{
			printf("YES\n");
			for (int t : ans) printf("%d ", t);
			return 0;
		}
	}

	printf("NO");
}