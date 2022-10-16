#include <bits/stdc++.h>
#define MAXN 200005
#define lld long long
#define ff(i,a,b) for(long long i=a; i<=b; i++)

using namespace std;


struct pqdata {
    int val;
    const bool operator< (const pqdata& other) const {
        return val > other.val;
    }
};
priority_queue<pqdata> pq;

int cnt[MAXN];

vector<pair<int, int>> edges;

vector<int> seq1;
vector<int> seq2;

int main() {
    int tmp;

    int n, m, ka, kb;
    scanf("%d %d %d %d", &n, &m, &ka, &kb);
    ff (i, 1, ka) {
        scanf("%d", &tmp);
        seq1.push_back(tmp);
        cnt[tmp]++;
    }
    ff (i, ka+1, m-1) {
        seq1.push_back(tmp);
        cnt[tmp]++;
    }
    ff (i, 1, kb) {
        scanf("%d", &tmp);
        seq2.push_back(tmp);
        cnt[tmp]++;
    }
    ff (i, kb+1, n-1) {
        seq2.push_back(tmp);
        cnt[tmp]++;
    }
    if (ka >= m || kb >= n) {
        printf("No\n");
        return 0;
    }

    ff (i, 1, n+m) {
        if (cnt[i] == 0) pq.push({i});
    }

    int it1 = 0;
    int it2 = 0;

    ff (i, 1, n+m-2) {
        // build a new edge!
        int a = pq.top().val;
        pq.pop();
        int b;
        if (a <= n) {
            // connect with the second
            b = seq2[it2++];
            cnt[b]--;
            if (cnt[b] == 0) pq.push({b});
        } else {
            // connect with the second
            b = seq1[it1++];
            cnt[b]--;
            if (cnt[b] == 0) pq.push({b});
        }
        edges.push_back({a, b});
    }
    int a = pq.top().val; pq.pop();
    int b = pq.top().val; pq.pop();
    edges.push_back({a, b});
    assert(pq.empty());
    printf("Yes\n");
    for (auto& edge : edges) {
        printf("%d %d\n", edge.first, edge.second);
    }
    return 0;
}