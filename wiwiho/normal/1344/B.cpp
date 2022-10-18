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

    vector<pii> d = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};

    int n, m;
    cin >> n >> m;

    vector<string> a(n + 2);
    int b = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = '.' + a[i] + '.';
        for(char j : a[i]) if(j == '#') b++;
    }
    a[0] = string(m + 2, '.');
    a[n + 1] = string(m + 2, '.');

    vector<int> rc(n + 2);
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 0; j <= m; j++){
            if(a[i][j] == '.' && a[i][j + 1] == '#') cnt++;
        }
//        cerr << i << " " << cnt << "\n";
        rc[i] = cnt;
        if(cnt == 0){
            for(int j = 1; j <= m; j++) a[i][j] = 't';
        }
        else if(cnt >= 2){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i = 1; i <= m; i++){
        int cnt = 0;
        for(int j = 0; j <= n; j++){
            if((a[j][i] == '.' || a[j][i] == 't') && a[j + 1][i] == '#') cnt++;
        }
//        cerr << i << " " << cnt << " " << a[0][i] << " " << a[1][i] << "\n";
        bool tmp = true;
        if(cnt == 0){
            tmp = false;
            for(int j = 1; j <= n; j++){
                if(a[j][i] == 't') a[j][i] = 'k', tmp = true;
            }
        }
        if(cnt >= 2 || !tmp){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++){
        if(rc[i] != 0) continue;
        bool tmp = false;
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 'k') tmp = true;
        }
        if(!tmp){
            cout << "-1\n";
            return 0;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != '#') continue;

            ans++;
            queue<pii> q;
            a[i][j] = 'v';
            q.push(mp(i, j));
            while(!q.empty()){
                pii now = q.front();
                q.pop();
                for(auto dr : d){
                    int nx = now.F + dr.F, ny = now.S + dr.S;
                    if(a[nx][ny] != '#') continue;
                    a[nx][ny] = 'v';
                    q.push(mp(nx, ny));
                }
            }
        }
    }

//    for(int i = 0; i <= n + 1; i++) printv(a[i], cerr);

    cout << ans << "\n";

    return 0;
}