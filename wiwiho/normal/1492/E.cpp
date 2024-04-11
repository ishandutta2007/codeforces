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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

vector<vector<int>> a;
int n, m;

int diff(vector<int>& v, vector<int>& u){
    int cnt = 0;
    for(int j = 0; j < m; j++){
        if(v[j] != u[j] && v[j] != -1 && u[j] != -1) cnt++;
    }
    return cnt;
}

void check(vector<int>& t){
    for(int i = 0; i < n; i++){
        if(diff(a[i], t) > 2) return;
    }
    cout << "Yes\n";
    printv(t, cout);
    exit(0);
}

void qaq3(int p1, int p2){
    vector<int> pos;
    for(int i = 0; i < m; i++){
        if(a[p1][i] != a[p2][i]) pos.eb(i);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j) continue;
            vector<int> t = a[p1];
            t[pos[j]] = a[p2][pos[j]];
            int q = pos[0 ^ 1 ^ 2 ^ i ^ j];
            t[q] = -1;
            for(int k = 0; k < n; k++){
                int tmp = diff(a[k], t);
                if(tmp > 2) goto nxt;
                if(tmp == 2){
                    t[q] = a[k][q];
                    break;
                }
            }
            if(t[q] == -1) t[q] = a[p1][q];
            check(t);
            nxt:;
        }
    }
    cout << "No\n";
    exit(0);
}

void qaq4(int p1, int p2){
    vector<int> pos;
    for(int i = 0; i < m; i++){
        if(a[p1][i] != a[p2][i]) pos.eb(i);
    }
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){

            vector<int> ano;
            for(int k = 0; k < 4; k++){
                if(k != i && k != j) ano.eb(pos[k]);
            }

            vector<int> t = a[p1];
            t[ano[0]] = a[p2][ano[0]];
            t[ano[1]] = a[p2][ano[1]];
            check(t);
        }
    }
    cout << "No\n";
    exit(0);
}

int main(){
    StarBurstStream

    cin >> n >> m;

    a.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int i = 1; i < n; i++){
        int tmp = diff(a[0], a[i]);
        if(tmp > 4){
            cout << "No\n";
            return 0;
        }
        if(tmp == 4) qaq4(0, i);
        if(tmp == 3) qaq3(0, i);
    }

    check(a[0]);

    return 0;
}