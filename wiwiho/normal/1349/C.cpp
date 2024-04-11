//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int n, m, t;
    cin >> n >> m >> t;

    vector<string> a(n + 2);
    a[0] = string(m + 2, ' ');
    a[n + 1] = string(m + 2, ' ');

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = ' ' + a[i] + ' ';
    }

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    queue<pii> q;
    vector<vector<int>> dis(n + 2, vector<int>(m + 2, -1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                if(a[i + dx[k]][j + dy[k]] == ' ') continue;
                if(a[i + dx[k]][j + dy[k]] == a[i][j]){
                    q.push(mp(i, j));
                    dis[i][j] = 0;
                    break;
                }
            }
        }
    }

    while(!q.empty()){
        int x = q.front().F, y = q.front().S;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(a[x + dx[i]][y + dy[i]] == ' ' || dis[x + dx[i]][y + dy[i]] != -1) continue;
            dis[x + dx[i]][y + dy[i]] = dis[x][y] + 1;
            q.push(mp(x + dx[i], y + dy[i]));
        }
    }

    while(t--){
        ll i, j, p;
        cin >> i >> j >> p;

        if(dis[i][j] == -1 || p <= dis[i][j]) cout << a[i][j] << "\n";
        else if((p - dis[i][j]) % 2) cout << (a[i][j] == '1' ? '0' : '1') << "\n";
        else cout << a[i][j] << "\n";
    }

    return 0;
}