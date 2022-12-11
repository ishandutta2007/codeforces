#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
#define int long long

using namespace std;

const int C = 14, INF = 1e18;

struct Node { 
    Node *go[C];
    Node *suff = 0, *prev = 0;
    int dp[2][1 << C];
    int add[C + 1];
    int pos;
    Node() {
        for (int i = 0; i < C; i++) {
            go[i] = 0;
            add[i] = 0;
        }
        for (int i = 0; i < (1 << C); i++) dp[0][i] = dp[1][i] = -INF;
        memset(add, 0, sizeof(add));
    }
};

Node *head;
vector <Node*> sorted;

void add(string s, int rght, int cc) {
    //cout << s << ' ' << rght << ' ' << cc << endl;
    int n = s.size();
    Node *t = head;
    for (int i = 0; i < n; i++) {
        int cur = s[i] - 'a';
        if (!t->go[cur]) {
            Node *x = new Node();
            x->prev = t;
            t->go[cur] = x;
        }
        t = t->go[cur];
    }
    t->add[rght] += cc;
}


void build() {
    queue <Node*> q;
    for (int i = 0; i < C; i++) {
        if (head->go[i]) {
            q.push(head->go[i]);
            head->go[i]->suff = head;
        } else {
            head->go[i] = head;
        }
    }
    sorted.push_back(head);
    while (!q.empty()) {
        Node *t = q.front();
        sorted.push_back(t);
        q.pop();
        for (int i = 0; i < C; i++) t->add[i] += t->suff->add[i];
        for (int i = 0; i < C; i++) {
            if (t->go[i]) {
                q.push(t->go[i]);
                t->go[i]->suff = t->suff->go[i];
            } else {
                t->go[i] = t->suff->go[i];
            }
        }
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int k;
    cin >> k;
    vector <pair <string, int>> v(k);
    for (int i = 0; i < k; i++) cin >> v[i].first >> v[i].second;
    string s;
    cin >> s;
    int n = s.length();
    int pos[n];
    int lst = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') pos[i] = lst++;
    }
    int res = 0;
    head = new Node();
    head->prev = head;
    for (auto elem : v) {
        int sz = elem.first.size();
        for (int i = 0; i + sz <= n; i++) {
            string cur = "";
            int llst = -1;
            bool flag = 1;
            for (int j = 0; j < sz; j++) {
                if (s[i + j] == '?') {
                    llst = pos[i + j];
                    cur += elem.first[j];
                    continue;
                }
                if (s[i + j] != elem.first[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                if (llst == -1) res += elem.second;
                else add(cur, llst, elem.second);
            }
        }
    }
    build();
    head->dp[0][0] = 0;
    int maxi = -INF;
    if (lst == 0) maxi = 0;
    reverse(sorted.begin(), sorted.end());
    for (int i = 0; i < lst; i++) {
        for (auto t : sorted) {
            for (int mask = 0; mask < (1 << C); mask++) {
                if (t->dp[0][mask] == -INF) continue;
                for (int nxt = 0; nxt < C; nxt++) {
                    if (mask & (1 << nxt)) continue;
                    Node *nt = t->go[nxt];
                    int nmask = mask | (1 << nxt);
                    nt->dp[1][nmask] = max(nt->dp[1][nmask], t->dp[0][mask] + nt->add[i]);
                    //cout << "here" << ' ' << t->dp[0][mask] << ' ' << nt->add[i] << endl;
                }
            }
        } 
        for (auto t : sorted) {
            for (int mask = 0; mask < (1 << C); mask++) {
                t->dp[0][mask] = t->dp[1][mask];
                t->dp[1][mask] = -INF;
                if (i == lst - 1) {
                    maxi = max(maxi, t->dp[0][mask]);
                }
            }
        }
    }
    //cout << res << ' ' << maxi << endl;
    cout << res + maxi << endl;
    return 0;
}