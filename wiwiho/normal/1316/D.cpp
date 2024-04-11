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

    int n;
    cin >> n;

    vector<vector<pii>> a(n, vector<pii>(n));
    vector<string> ans(n, string(n, '?'));

    queue<pii> x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j].F >> a[i][j].S;
            if(a[i][j].F != -1) a[i][j].F--, a[i][j].S--;
            if(a[i][j].F != -1)
                ans[a[i][j].F][a[i][j].S] = 'X';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] == 'X' && a[i][j] != mp(i, j)){
                cout << "INVALID\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] == 'X') x.push(mp(i, j));
        }
    }

    vector<pair<pii, char>> d = {mp(mp(0, 1), 'L'),
                                 mp(mp(1, 0), 'U'),
                                 mp(mp(0, -1), 'R'),
                                 mp(mp(-1, 0), 'D')};
    while(!x.empty()){
        queue<pii> q;
        pii t = x.front();
//        cerr << t << "\n";
        q.push(t);
        x.pop();
        while(!q.empty()){
//            cerr << "test " << q.front() << "\n";
            for(auto i : d){
                int nx = q.front().F + i.F.F, ny = q.front().S + i.F.S;
//                cerr << nx << " " << ny << "\n";
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != t || ans[nx][ny] != '?') continue;
                ans[nx][ny] = i.S;
                q.push(mp(nx, ny));
            }
            q.pop();
        }
    }

//    for(int i = 0; i < n; i++) printv(ans[i], cerr);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != mp(-1, -1) && ans[i][j] == '?'){
                cout << "INVALID\n";
                return 0;
            }
        }
    }

    d = {mp(mp(0, 1), 'R'),
         mp(mp(1, 0), 'D'),
         mp(mp(0, -1), 'L'),
         mp(mp(-1, 0), 'U')};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != mp(-1, -1)) continue;
            for(auto k : d){
                int nx = i + k.F.F, ny = j + k.F.S;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != mp(-1, -1)) continue;
                ans[i][j] = k.S;
                break;
            }
            if(ans[i][j] == '?'){
                cout << "INVALID\n";
                return 0;
            }
        }
    }

    cout << "VALID\n";
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";

    return 0;
}