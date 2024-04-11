//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    vector<pii> d = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};

    int T;
    cin >> T;

    while(T--){

        int n, m;
        cin >> n >> m;

        vector<string> a(n + 2, string(m + 2, '#'));
        for(int i = 1; i <= n; i++){
            string t;
            cin >> t;
            a[i] = "#" + t + "#";
        }

        bool ans = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] != 'B') continue;
                for(pii k : d){
                    char& c = a[i + k.F][j + k.S];
                    if(c == 'G') ans = false;
                    else if(c == '.') c = '#';
                }
            }
        }
//        for(int i = 0; i <= n + 1; i++) printv(a[i], cerr);

        vector<vector<bool>> vst(n + 2, vector<bool>(m + 2));
        queue<pii> q;
        if(a[n][m] != '#'){
            vst[n][m] = true;
            q.push(mp(n, m));
        }
        while(!q.empty()){
            pii now = q.front();
            q.pop();
            for(pii i : d){
                int nx = now.F + i.F;
                int ny = now.S + i.S;
                if(!vst[nx][ny] && a[nx][ny] != '#'){
                    vst[nx][ny] = true;
                    q.push(mp(nx, ny));
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 'G' && !vst[i][j]) ans = false;
            }
        }

        if(ans) cout << "Yes\n";
        else cout << "No\n";

    }

    return 0;
}