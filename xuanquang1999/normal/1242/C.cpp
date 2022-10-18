#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXK = 15;

int k;
vector<int> a[MAXK];
map<long long, int> ma[MAXK];
long long sum[MAXK];

vector<pii> target[MAXK];
vector<pii> cyc[1<<MAXK];

bool dp[1<<MAXK];
int trace[1<<MAXK];
pii ans[MAXK];

int main() {
    long long req = 0;

    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int n;
        scanf("%d", &n);

        a[i].resize(n);
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);

            ma[i][a[i][j]] = j;
            sum[i] += a[i][j];
        }

        req += sum[i];
    }

    if (req % k != 0) {
        puts("No");
        return 0;
    }

    // for(int i = 0; i < k; ++i) {
    //     for(int x: a[i]) 
    //         printf("%d ", x);
    //     puts("");
    // }


    req /= k;

    for(int i = 0; i < k; ++i) {
        for(auto e: ma[i]) {
            int val = e.first, j = e.second;
            long long rem = req - (sum[i] - val);
            
            target[i].resize(a[i].size());
            target[i][j] = {-1, -1};

            // printf("%d %d %lld %lld %d\n", i, j, req, sum[i], val);
            for(int u = 0; u < k; ++u) 
                if (ma[u].count(rem) && (u != i || ma[u][rem] == j)) 
                    target[i][j] = {u, ma[u][rem]};            
        }
    }

    // for(int i = 0; i < k; ++i) {
    //     for(auto e: target[i]) 
    //         printf("(%d, %d) ", e.first, e.second);
    //     puts("");
    // }

    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < ma[i].size(); ++j) {
            int mask = 0;
            pii u = {i, j};

            vector<pii> cur;
            
            vector<bool> visited(k, false);
            while (u.first != -1 && !visited[u.first]) {
                cur.push_back(u);                
                visited[u.first] = true;
                mask |= 1 << u.first;

                u = target[u.first][u.second];
            }

            if (u.first == i && u.second == j)
                cyc[mask] = cur;
        }
    }

    // for(int mask = 0; mask < (1<<k); ++mask) {
    //     printf("%d:", mask);
    //     for(auto e: cyc[mask])
    //         printf(" (%d, %d)", e.first, e.second);
    //     puts("");
    // }
        

    dp[0] = true;
    trace[0] = 0;

    for(int mask = 1; mask < (1<<k); ++mask) {
        for (int sub = mask; sub > 0; sub = (sub-1) & mask) {
            if (!cyc[sub].empty() && dp[mask^sub]) {
                dp[mask] = true;
                trace[mask] = sub;
            }            
        }
    }

    int mask = (1<<k) - 1;

    if (!dp[mask]) {
        puts("No");
        return 0;
    }

    while (mask > 0) {
        int sub = trace[mask];

        vector<pii> v = cyc[sub];
        
        // for(auto e: v) 
        //     printf("(%d, %d) ", e.first, e.second);
        // puts("");

        for(int i = 0; i < v.size(); ++i) {
            int j = (i + 1) % v.size();
            int cur = v[i].first, nxt = v[j].first;
            ans[nxt] = {a[nxt][v[j].second], cur};
        }

        mask ^= sub;
    }

    puts("Yes");
    for(int i = 0; i < k; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second + 1);
    
    return 0;
}