#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5007, INF = 3e18;

struct Node{
    int cnt = 0, cnt0 = 0;
    Node *pr;
    map <int, Node*> go;
    Node() {}
};

bool isprime(int n) {
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}

vector <int> pr;
vector <int> fact[N];
int cntt[N];
Node *tail[N];
int allsz;
Node *head = new Node();
int ans = INF;

void add(int x, int w) {
    Node *t = head;
    int s = 0;
    for (int elem : fact[x]) s += elem;
    for (int i = allsz - 1; i >= 0; i--) {
        t->cnt += s * w;
        t->cnt0 += w;
        s -= fact[x][i];
        if (t->go.find(fact[x][i]) == t->go.end()) t->go[fact[x][i]] = new Node();
        t = t->go[fact[x][i]];
    }
}

void init() {
    pr.push_back(0);
    for (int i = 2; i < N; i++) {
        if (isprime(i)) pr.push_back(i);
    }
    allsz = pr.size();
    fact[0].assign(allsz, 0);
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1];
        int n = i;
        for (int j = 1; j < allsz; j++) {
            while (n % pr[j] == 0) {
                n /= pr[j];
                fact[i][j]++;
            }
            if (n == 1) break;
        }
    }
}

void rec(Node *t, int res = 0, int cnt = 0) {
    int s = 0, cnt0 = 0;
    int less = 0, more = 0;
    for (auto elem : t->go) {
        s += elem.second->cnt;
        cnt0 += elem.second->cnt0;
        more += elem.first * elem.second->cnt0;
        //if (more != 0) cout << elem.first << ' ' << elem.second->cnt0 << endl;
    }
    int cless = 0, cmore = cnt0;
    if (s + res + more < ans) {
        //cout << res << ' ' << cnt << ' ' << cnt0 << ' ' << s << ' ' << more << endl;
    }
    ans = min(ans, s + res + more);
    int pst = 0;
    for (auto elem : t->go) {
        less += (elem.first - pst) * cless;
        more -= (elem.first - pst) * cmore;
        cmore -= elem.second->cnt0;
        cless += elem.second->cnt0;
        int ncnt = cnt + (cnt0 - elem.second->cnt0);
        int nres = res + cnt * elem.first + (s - elem.second->cnt) + less + more;
        rec(elem.second, nres, ncnt);
        pst = elem.first;
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin >> n;
    memset(cntt, 0, sizeof(cntt));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cntt[x]++;
    }
    for (int i = 0; i < N; i++) {
        if (cntt[i] != 0) add(i, cntt[i]);
    }
    rec(head);
    cout << ans << endl;
    return 0;
}