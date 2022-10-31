#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,l[500001],r[500001];
struct seg_tr{
    const static int MAX = 1000000;
    int tr[MAX + 1];
    void upd(int cur, int val) {
        while(cur<=MAX) tr[cur] += val, cur += cur & -cur;
    }
    int get(int cur) {
        int ret=0; 
        while(cur) ret += tr[cur], cur -= cur & -cur;
        return ret;
    }
    int sum(int l,int r) {
        return get(r) - get(l-1);
    }
}st;
vector<int> adj[500001];

int vis[500001],vc;
void dfs(int cur) {
    vc++;
    vis[cur] = 1;
    for(auto &it:adj[cur]) if(!vis[it]) dfs(it);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",l+i,r+i);

    vector<pii> arr(n*2);
    for(int i=1;i<=n;i++) arr[i*2-2] = pii(l[i], i), arr[i*2-1] = pii(r[i], -i);
    sort(arr.begin(),arr.end());

    long long cnt = 0;
    for(auto &v: arr) {
        if(v.second > 0) st.upd(v.first, 1);
        else {
            cnt += st.sum(l[-v.second] + 1, v.first);
            st.upd(l[-v.second], -1);
        }
    }
    
    if(cnt != n-1) {
        puts("NO");
        return 0;
    }
    
    set<pii> tr;
    for(auto &v:arr) {
        if(v.second > 0) tr.insert(v);
        else {
            auto it = tr.lower_bound({l[-v.second], -v.second});
            for(auto jt = next(it); jt != tr.end(); jt++) {
                adj[-v.second].push_back(jt->second);
                adj[jt->second].push_back(-v.second);
            }
            tr.erase(it);
        }
    }
    dfs(1);
    if(vc == n) puts("YES");
    else puts("NO");
    
    return 0;
}