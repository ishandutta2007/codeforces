#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const int inf = 1e9;

int n, m;

vector<int> dp;
vector<list<int> > gr;

lint ans = 0ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    dp.resize(n);
    gr.resize(n);
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--; u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        int cmax = 0;
        int sz = 0;
        for(auto it = gr[i].begin(); it != gr[i].end(); it++){
            int prev = *it;
            sz++;
            if(prev >= i){continue;}
            cmax = max(cmax, dp[prev]);
        }
        dp[i] = cmax + 1;
        lint curr = dp[i] * 1ll * sz;
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}