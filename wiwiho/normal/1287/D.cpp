//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<vector<int>> g;
vector<int> c, ans;

vector<int> dfs(int now){
    int cnt = 0;
    vector<int> r;
    r.eb(now);
    ans[now] = c[now] + 1;
    for(int i : g[now]){
        vector<int> t = dfs(i);
        for(int j : t){
            ans[j] += cnt;
            if(ans[j] >= c[now] + 1) ans[j]++;
            r.eb(j);
        }
        cnt += t.size();
    }
    if(r.size() < c[now] + 1){
        cout << "NO\n";
        exit(0);
    }
    return r;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    c.resize(n + 1);
    ans.resize(n + 1);
    int root = 0;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        if(p == 0) root = i;
        else g[p].eb(i);
        cin >> c[i];
    }

    dfs(root);

    cout << "YES\n";
    ans.erase(ans.begin());
    printv(ans, cout);

    return 0;
}