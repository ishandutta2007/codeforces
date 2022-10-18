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

    int T;
    cin >> T;

    while(T--){

        int n, x, y;
        cin >> n >> x >> y;

        vector<int> b(n);
        vector<int> cnt(n + 2);
        vector<set<int>> s(n + 1);
        vector<bool> use(n + 2);
        for(int i = 0; i < n; i++){
            cin >> b[i];
            cnt[b[i]]++;
            s[cnt[b[i]]].insert(i);
            use[b[i]] = true;
        }
        int c = -1;
        for(int i = 1; i <= n + 1; i++){
            if(!use[i]){
                c = i;
                break;
            }
        }

        vector<int> tb = b;

        int tmp = x;
        for(int i = n; i > 0 && tmp; i--){
            while(tmp && !s[i].empty()){
                tmp--;
//                cerr << cnt[*s[i].begin()] << "\n";
                cnt[b[*s[i].begin()]]--;
                s[i].erase(s[i].begin());
            }
        }

//        printv(cnt, cerr);
        int sum = n - x;

        for(int i = 1; i <= n + 1; i++){
            if(cnt[i] <= sum / 2) continue;
            while(cnt[i] > sum / 2 && cnt[i] > 0){
                int t = -1;
                for(int j : s[cnt[i]]){
                    if(b[j] != i) continue;
                    t = j;
                    break;
                }
                b[t] = c;
                s[cnt[i]].erase(t);
                cnt[i]--;
                sum--;
            }
        }
        if(sum < y - x){
            cout << "NO\n";
            continue;
        }

        vector<pii> v;
        tmp = sum;
        for(int i = n; i > 0 && tmp; i--){
            while(tmp && !s[i].empty()){
                tmp--;
                v.eb(mp(b[*s[i].begin()], *s[i].begin()));
                s[i].erase(s[i].begin());
            }
        }

        lsort(v);
//        printv(v, cerr);
        for(int i = 0; i < sum; i++){
            b[v[i].S] = v[(i + sum / 2) % sum].F;
        }
        for(int i = y - x; i < sum; i++){
            b[v[i].S] = c;
        }

        cout << "YES\n";
        printv(b, cout);

    }

    return 0;
}