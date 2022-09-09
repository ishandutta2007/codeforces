#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

struct Seg {
    int tree[1050000];
    int key;
    void init(int n) {
        key = 1;
        while (key < n) key *= 2;
        for (int i = 0; i < key * 2; i++) {
            tree[i] = 0;
        }
    }
    void upd(int idx, int val) {
        idx += key;
        while (idx) {
            tree[idx] = max(tree[idx], val);
            idx /= 2;
        }
    }
    int getv(int s, int e) {
        s += key;
        e += key;
        int ans = 0;
        while (s <= e) {
            if (s & 1) ans = max(ans, tree[s]);
            if (~e & 1) ans = max(ans, tree[e]);
            s = (s + 1) / 2;
            e = (e - 1) / 2;
        }
        return ans;
    }
    int geti(int s, int e) {
        s += key;
        e += key;
        int ans = 0;
        int tloc = -1;
        while (s <= e) {
            if (s & 1) {
                if (ans <= tree[s]) {
                    ans = tree[s];
                    tloc = s;
                }
            }
            if (~e & 1) {
                if (ans <= tree[e]) {
                    ans = tree[e];
                    tloc = e;
                }
            }
            s = (s + 1) / 2;
            e = (e - 1) / 2;
        }
        while (tloc < key) {
            if (tree[tloc * 2] > tree[tloc * 2 + 1])
                tloc *= 2;
            else
                tloc = tloc * 2 + 1;
        }
        return tloc - key;
    }
} itp, ita;

int N, Q;
int P[300100], A[300100];
vector<pii> rans;

bool dnc(int s, int e, int mini) {
    if (s > e) return false;
    int m = itp.geti(s, e);
    if (A[m] == 0) {
        rans.emplace_back(ita.getv(s, e) + 1, mini - 1);
        return dnc(s, m - 1, mini) || dnc(m + 1, e, mini);
    } else {
        if (A[m] >= mini) return true;
        return dnc(s, m - 1, min(mini, A[m])) || dnc(m + 1, e, min(mini, A[m]));
    }
}

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d%d", &N, &Q);
        int K = 0;
        for (int i = 0; i < N; i++) scanf("%d", &P[i]);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            if (A[i] == 0) K++;
        }
        itp.init(N);
        ita.init(N);
        for (int i = 0; i < N; i++) {
            itp.upd(i, P[i]);
            ita.upd(i, A[i]);
        }
        rans.clear();
        bool mang = dnc(0, N - 1, INF);
        if (!mang) {
            for (pii &v : rans) {
                if (v.first > v.second) {
                    mang = true;
                    break;
                }
            }
        }
        if (mang) {
            for (int i = 0; i < K - 1 + Q; i++) {
                scanf("%*d");
            }
            for (int i = 0; i < Q; i++) {
                puts("NO");
            }
            continue;
        }
        vector<int> S;
        for (int i = 0; i < K - 1; i++) {
            int s;
            scanf("%d", &s);
            S.push_back(s);
        }
        sort(S.begin(), S.end());
        int em = -1, sm = -1;
        {
            sort(rans.begin(), rans.end());
            int j = 0;
            priority_queue<int, vector<int>, greater<>> pq;
            for (int i = 0; i < K - 1; i++) {
                while (j < rans.size() && rans[j].first <= S[i]) {
                    pq.push(rans[j].second);
                    j++;
                }
                while (!pq.empty() && pq.top() < S[i]) {
                    em = pq.top();
                    pq.pop();
                }
                if (pq.empty()) {
                    mang = true;
                    break;
                }
                pq.pop();
            }
            if (mang) {
                for (int i = 0; i < Q; i++) {
                    scanf("%*d");
                }
                for (int i = 0; i < Q; i++) {
                    puts("NO");
                }
                continue;
            }
            while (j < rans.size()) {
                pq.push(rans[j].second);
                j++;
            }
            if (!pq.empty()) {
                em = pq.top();
                pq.pop();
            }
        }

        {
            sort(rans.begin(), rans.end(),
                 [](pii &A, pii &B) { return A.second < B.second; });
            int j = (int)rans.size() - 1;
            priority_queue<int> pq;
            for (int i = K - 2; i >= 0; i--) {
                while (j >= 0 && rans[j].second >= S[i]) {
                    pq.push(rans[j].first);
                    j--;
                }
                while (!pq.empty() && pq.top() > S[i]) {
                    sm = pq.top();
                    pq.pop();
                }
                if (pq.empty()) {
                    mang = true;
                    break;
                }
                pq.pop();
            }
            if (mang) {
                for (int i = 0; i < Q; i++) {
                    scanf("%*d");
                }
                for (int i = 0; i < Q; i++) {
                    puts("NO");
                }
                continue;
            }
            while (j >= 0) {
                pq.push(rans[j].first);
                j--;
            }
            if (!pq.empty()) {
                sm = pq.top();
                pq.pop();
            }
        }

        for (int i = 0; i < Q; i++) {
            int s;
            scanf("%d", &s);
            if (sm <= s && s <= em) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }

    return 0;
}