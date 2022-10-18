#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

void dfs(int now, vector<vector<int>>& g, vector<bool>& choose, vector<bool>& visit, vector<bool>& book){
    if(!book[now]){
        choose[now] = true;
    }
    book[now] = true;
    visit[now] = true;
    for(int i = 0; i < g[now].size(); i++){
        if(choose[now]){
            book[g[now][i]] = true;
        }
        if(!visit[g[now][i]]){
            dfs(g[now][i], g, choose, visit, book);
        }
    }
}

int main(){

    StarBurstStream

    int t;
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n + 1);
        vector<int> s(n + 1);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }

        vector<bool> choose(n + 1);
        vector<bool> visit(n + 1);
        vector<bool> book(n + 1);
        dfs(1, g, choose, visit, book);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(choose[i]){
                ans++;
            }
        }
        if(ans > n / 2){
            cout << n - ans << "\n"; 
            for(int i = 1; i <= n; i++){
                if(!choose[i]){
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
        else{
            cout << ans << "\n";
            for(int i = 1; i <= n; i++){
                if(choose[i]){
                    cout << i << " ";
                }
            }
            cout << "\n";
        }

    }
    return 0;
}