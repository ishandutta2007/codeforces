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
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
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

pii trans(int id, int m){
    int x = (id - 1) / m + 1;
    int y = id - (x - 1) * m;
    return mp(x, y);
}

int trans(int x, int y, int m){
    return (x - 1) * m + y - 1;
}

int operator-(pii a, pii b){
    return abs(a.F - b.F) + abs(a.S - b.S);
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    if(n <= 3 && m <= 3){

        vector<int> ans(n * m);
        for(int i = 0; i < n * m; i++) ans[i] = i + 1;

        do{
            bool ok = true;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    int now = trans(i, j, m);
                    int now1 = trans(i + 1, j, m);
                    int now2 = trans(i, j + 1, m);
//                    cerr << now << " " << now1 << " " << now2 << "\n";
                    if(i < n && trans(ans[now], m) - trans(ans[now1], m) == 1) ok = false;
                    if(j < m && trans(ans[now], m) - trans(ans[now2], m) == 1) ok = false;
                }
            }
            if(ok){
                cout << "YES\n";
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= m; j++){
                        cout << ans[trans(i, j, m)] << " ";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        while(next_permutation(iter(ans)));

        cout << "NO\n";

        return 0;
    }

    bool f = false;
    if(m <= 3){
        swap(n, m);
        f = true;
    }
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> p(1);
    for(int i = m - !(m % 2); i > 0; i -= 2) p.eb(i);
    for(int i = m - (m % 2); i > 0; i -= 2) p.eb(i);
//    printv(p, cerr);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i % 2) a[i][j] = trans(i, p[j], m);
            else if(m > 4) a[i][j] = trans(i, p[j + 1 > m ? j + 1 - m : j + 1], m);
            else a[i][j] = trans(i, p[m - j + 1], m);
//            else a[i][j] = trans(i, p[j], m);
        }
    }

    if(f){
        vector<vector<int>> aa(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x, y;
                tie(x, y) = trans(a[i][j] + 1, m);
//                cerr << x << " " << y << " " << a[i][j] << "\n";
                aa[j][i] = trans(y, x, n);
            }
        }
        a = aa;
        swap(n, m);
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}