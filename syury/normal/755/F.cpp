//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6 + 6;

int n, k;
int p[N];
vector<vector<int> > cycles;

int solvemx(){
    int col[N];
    memset(col, 0, sizeof(col));
    int rem = k;
    for(auto& c: cycles){
        if(c.size() == 1u)
            continue;
        for(size_t i = 1; i < c.size(); i += 2){
            if(rem){
                --rem;
                col[c[i]] = 1;
            }
        }
    }
    for(auto& c: cycles){
        if(rem && c.size()&1){
            col[c.back()] = 1;
            --rem;
        }
    }
    int ans = 0;
    for(auto& c: cycles){
        for(size_t i = 0; i < c.size(); i++){
            int j = i + 1;
            if(j == c.size())j = 0;
            ans += int(col[c[i]] || col[c[j]]);
        }
    }
    return ans;
}

int solvemi(){
    bitset<N> dp;
    dp.reset();
    dp[0] = 1;
    vector<int> lens;
    for(auto& c: cycles)
        lens.push_back(c.size());
    sort(all(lens));
    size_t i = 0;
    while(i < lens.size()){
        size_t j = i;
        while(j < lens.size() && lens[j] == lens[i])
            ++j;
        int cnt = j - i;
        int pw = 1;
        while(pw <= cnt){
            dp |= dp<<(lens[i]*pw);
            cnt -= pw;
            pw <<= 1;
        }
        if(cnt)
            dp |= dp<<(lens[i]*cnt);
        i = j;
    }
    return k + 1 - int(dp[k]);
}

void solve(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", p + i);
        --p[i];
    }
    bool used[N];
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++){
        if(used[i])
            continue;
        int v = p[i];
        vector<int> curr = {i};
        used[i] = 1;
        while(v != i){
            curr.push_back(v);
            used[v] = 1;
            v = p[v];
        }
        cycles.push_back(curr);
    }
    printf("%d %d\n", solvemi(), solvemx());
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}