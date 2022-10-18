#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ull unsigned long long
#define endl '\n'
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back 
#define ceil(x,y) (x+y-1)/y
#define deb(x) { cerr << #x << '=' << x << '\n'; }
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN = 110;
vector<int> graph[MAXN], res, pth;
int h[MAXN];
bool used[MAXN];
void dfs(int v, int p){
    for (auto i: graph[v]){
        if (i == p) continue;
        h[i] = h[v] + 1;
        dfs(i, v);
    }
}
void ddfs(int v, int p){
    res.pb(v);
    int cc = 0;
    for (auto i: graph[v]){
        if (i == p) continue;
        if (used[i]){
            ddfs(i, v);
            res.pb(v);
            cc++;
        }
    }
}
void bfs(int &l){
    queue<int> q;
    for (auto i: pth) used[i] = 1, q.push(i);
    while (!q.empty()){
        bool flag = 0;
        int v = q.front();
        q.pop();
        for (auto i: graph[v]){
            if (used[i]) continue;
            used[i] = 1;
            q.push(i);
            --l;
            if (l == 0){
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    for (int i = 0; i < (int) pth.size(); ++i){
        res.pb(pth[i]);
        for (auto j: graph[pth[i]]){
            if (i > 0 && j == pth[i - 1]) continue;
            if (i < (int) pth.size() - 1 && j == pth[i + 1]) continue;
            if (used[j]){
                ddfs(j, pth[i]);
                res.pb(pth[i]);
            }
        }
    }
}

void solve(){
    res.clear();
    for (int i = 0; i < MAXN; ++i) graph[i].clear();
    memset(h, 0, sizeof(h));
    memset(used, 0, sizeof(used));
    pth.clear();
    int n, l;
    cin >> n >> l;
    int p[n + 1];
    for (int i = 2; i <= n; ++i){
        int v;
        cin >> v;
        p[i] = v;
        graph[v].pb(i);
        graph[i].pb(v);
    }
    h[1] = 1;
    dfs(1, 0);
    int max_h = *max_element(h, h + MAXN), deep = 0;
    for (int i = 1; i <= n; ++i){
        if (h[i] == max_h){
            deep = i;
            break;
        }
    }
    int temp = deep;
    while (temp != 1){
        pth.pb(temp);
        temp = p[temp];
    }
    pth.pb(1);
    reverse(pth.begin(), pth.end());
    if (l <= max_h){
        cout << l - 1 << endl;
        for (int i = 0; i < l; ++i){
            cout << pth[i] << ' ';
        }
        cout << endl;
        return;
    }
    l -= max_h;
    bfs(l);
    cout << (int) res.size() - 1 << endl;
    for (auto i: res){
        cout << i << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    int t;cin >> t;while(t--) 
    solve();
}