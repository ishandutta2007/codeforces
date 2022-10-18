//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<vector<int>> ans;
int n;

int d[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};

void dfs(int x, int y, int c){
    ans[x][y] = c;
    for(int i = 0; i < 8; i++){
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
        if(ans[nx][ny] != 0) continue;
        dfs(nx, ny, c == 1 ? 2 : 1);
    }
}

int main(){
    StarBurstStream

    cin >> n;
    ans.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    if(ans[i][j] == 0)
    dfs(0, 0, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] == 1) cout << "W";
            else cout << "B";
        }
        cout << "\n";
    }

    return 0;
}