#include <map>
#include <cstdio>

using namespace std;

int n[15], k;
map<int, int> M;
long long sum[15];
long long goal;

int num[15*5000];
int b[15*5000];
int C = 0;

int v[15*5000]; // -1 : done, 0 : yet, 1 : going

int next(int x) {
    int u = b[x];
    auto it = M.find(goal - (sum[u] - num[x]));
    if(it == M.end()) return -1;
    return it->second;
}

int dp[1<<15];

void adddp(int set, int root) {
    //printf("*****%d %d\n", set, root);
    if(dp[set] != 0) return;
    dp[set] = -1-root;
    for(int i=1; i<(1<<k); i++) {
        if(!dp[i]) continue;
        if(set & i) continue;
        dp[i|set] = set;
    }
}

int now;

int dfs(int x) {
    if (v[x] == 1)
    {
        now = 1<<b[x];
        v[x] = -1;
        return x;
    }
    
    v[x] = 1;
    int t = next(x);
    if(t == -1 || v[t] == -1) return v[x] = -1;

    int r = dfs(t);
    if(r == -1) return v[x] = -1;
    if(r == x) {
        adddp(now, x);
        return v[x] = -1;
    }
    if((now >> b[x])&1) return v[x] = -1;
    now |= (1<<b[x]);
    v[x] = -1;
    return r;
}

int ans[15][2];

void makeans(int x) {
    int t = dp[x];
    if(t > 0) {
        makeans(t);
        makeans(x-t);
    }
    else {
        t = -t - 1;
        int i = t;
        do {
            int u = b[i];
            auto it = M.find(goal - (sum[u] - num[i]));
            int next = it->second;
            ans[b[next]][0] = num[next];
            ans[b[next]][1] = u + 1;
            i = next;
        } while(i != t);
    }
}

int main() {
    int t;
    long long S = 0;
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        scanf("%d", n+i);
        for(int j=0; j<n[i]; j++) {
            scanf("%d", &t);
            num[C] = t;
            b[C] = i;
            sum[i] += t;
            M[t] = C;
            C++;
        }
        //printf("*****%d\n", sum[i]);
        S += sum[i];
    }
    if(S % k != 0) {
        printf("No\n");
        return 0;
    }
    goal = S / k;
        //printf(")))))%d\n", goal);
    for(int i=0; i<C; i++) {
        if(!v[i]) dfs(i);
    }
    // ans
    t = (1<<k)-1;
    if(dp[t] == 0) {
        printf("No\n");
        return 0;
    }
    makeans(t);
    printf("Yes\n");
    for(int i=0; i<k; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}