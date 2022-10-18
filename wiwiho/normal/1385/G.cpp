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

int n;
int trans(pii a){
    return n * a.S + a.F;
}

int neg(pii a){
    return trans(mp(a.F, !a.S));
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        cin >> n;

        vector<int> a1(n), a2(n);
        vector<vector<pii>> ap(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a1[i];
            ap[a1[i]].eb(mp(i, 0));
        }
        for(int i = 0; i < n; i++){
            cin >> a2[i];
            ap[a2[i]].eb(mp(i, 1));
        }

        bool ans = true;
        vector<vector<int>> g(2 * n);
        for(int i = 1; i <= n; i++){
            if(ap[i].size() != 2){
                ans = false;
                break;
            }
            pii a = ap[i][0], b = ap[i][1];
            if(a.F == b.F) continue;
//            cerr << i << " " << a << " " << b << "\n";
//            if(a.S != b.S){
                g[trans(a)].eb(neg(b));
                g[neg(b)].eb(trans(a));
                g[neg(a)].eb(trans(b));
                g[trans(b)].eb(neg(a));
//            }
//            else{
//                g[trans(a)].eb(trans(b));
//                g[trans(b)].eb(trans(a));
//                g[neg(a)].eb(neg(b));
//                g[neg(b)].eb(neg(a));
//            }
        }
//        for(int i = 0; i < 2 * n; i++){
//            cerr << i << "  ";
//            printv(g[i], cerr);
//        }

        if(!ans){
            cout << "-1\n";
            continue;
        }

        vector<int> cnt(2 * n);
        vector<int> id(2 * n, -1);
        vector<int> ch(2 * n);
        int ts = 0;

        for(int i = 0; i < 2 * n; i++){
            if(id[i] != -1) continue;
            queue<int> q;
            q.push(i);
            id[i] = ts;
            while(!q.empty()){
                int now = q.front();
                q.pop();
                for(int j : g[now]){
                    if(id[j] != -1) continue;
                    q.push(j);
                    id[j] = ts;
                }
            }
            ts++;
        }
//        printv(id, cerr);

        for(int i = 0; i < n; i++){
            if(id[trans(mp(i, 0))] == id[trans(mp(i, 1))]){
                ans = false;
                break;
            }
            cnt[id[trans(mp(i, 1))]]++;
        }
        if(!ans){
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++){
            if(ch[id[i]] != 0) continue;
            if(cnt[id[trans(mp(i, 0))]] < cnt[id[trans(mp(i, 1))]]){
                ch[id[trans(mp(i, 0))]] = 2;
                ch[id[trans(mp(i, 1))]] = 1;
            }
            else{
                ch[id[trans(mp(i, 0))]] = 1;
                ch[id[trans(mp(i, 1))]] = 2;
            }
        }

        vector<int> rv;
        for(int i = 0; i < n; i++){
            if(ch[id[trans(mp(i, 1))]] == 2) rv.eb(i + 1);
        }
        cout << rv.size() << "\n";
        printv(rv, cout);

    }

    return 0;
}