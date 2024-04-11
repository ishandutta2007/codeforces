#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> lis[500100];
int nxt[500100];
int ans[500100];

int cnt;
void dfs(int here) {
    ans[here] = cnt; cnt--;
    for (int &there :lis[here]) {
        dfs(there);
    }
}

vector<int> plis[500100];
int main() {
    int tt;

    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        int i, maxi = 0, flag = 0;
        for (i=0;i<n;i++) {
            scanf("%d",&nxt[i]);
            if (nxt[i]>=0) lis[--nxt[i]].push_back(i);
            else lis[(nxt[i]=i+1)].push_back(i);
        }
        stack<int> st;
        for (i=0;i<=n;i++) {
            if (i!=n) plis[nxt[i]].push_back(i);
            while(!plis[i].empty()) {
                if (st.empty()||st.top()!=plis[i].back()) {
                    flag = 1;
                    break;
                }
                plis[i].pop_back();
                st.pop();
            }
            if (flag) break;
            st.push(i);
        }
        for (i=0;i<=n;i++) plis[i].clear();
        if (flag) {
            printf("-1\n");
        }
        else {
            for (i=0;i<=n;i++) ans[i] = -1;
            cnt = n;
            dfs(n);
            for (i=0;i<n;i++) printf("%d ",ans[i]+1); printf("\n");
        }
        for (i=0;i<=n;i++) lis[i].clear();
    }

    return 0;
}