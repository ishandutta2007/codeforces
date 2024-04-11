#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int nTest, n, k, ans[MAXN];
vector<int> pos[MAXN];
bool inSet[MAXN];

int ask(vector<int> setId) {
    vector<int> ind;
    for(int i: setId)
        for(int u: pos[i])
            ind.push_back(u);

    printf("? %d", ind.size());
    for(int u: ind)
        printf(" %d", u);
    puts("");
    fflush(stdout);

    int res;
    scanf("%d", &res);
    return res;
}

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &k);

        for(int i = 0; i <= k; ++i) 
            pos[i].clear();
        fill(inSet, inSet+n+1, false);

        for(int i = 0; i < k; ++i) {
            pos[i].clear();
            int c; scanf("%d", &c);
            while (c--) {
                int u; scanf("%d", &u);
                pos[i].push_back(u);
                inSet[u] = true;
            }
        }
        for(int u = 1; u <= n; ++u)
            if (!inSet[u])
                pos[k].push_back(u);

        vector<int> cur;
        for(int i = 0; i <= k; ++i)
            cur.push_back(i);        
        int maxA = ask(cur);

        while (cur.size() > 1) {
            // printf("cur:");
            // for(int i: cur)
            //     printf(" %d", i);
            // puts("");

            vector<int> toAsk;
            for(int i = 0; i < cur.size(); i += 2)
                toAsk.push_back(cur[i]);
            int maxAsk = ask(toAsk);

            vector<int> nxt;
            for(int i = (maxAsk != maxA); i < cur.size(); i += 2)
                nxt.push_back(cur[i]);
            cur.swap(nxt);
        }

        int maxSetId = cur[0];
        for(int i = 0; i <= k; ++i)
            if (i != maxSetId)
                ans[i] = maxA;
        
        cur.clear();
        for(int i = 0; i <= k; ++i)
            if (i != maxSetId)
                cur.push_back(i);
        ans[maxSetId] = ask(cur);


        printf("!");
        for(int i = 0; i < k; ++i)
            printf(" %d", ans[i]);
        puts("");
        fflush(stdout);

        string res;
        cin >> res;
        if (res == "Incorrect")
            return 0;
    }


    return 0;
}