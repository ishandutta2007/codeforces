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

    int n;
    cin >> n;

    int tmp = 1, tt = 0;
    for(int i = 2; i <= n; i++){
        int cnt = n / i * (i - 1);
        if(n % i) cnt += n % i - 1;
        cnt -= i - 1;
        if(cnt > tt) tmp = i, tt = cnt;
    }

    vector<bool> pos(n, true);
    pos[n - 1] = false;
    for(int i = tmp - 1; i < n; i += tmp) pos[i] = false;
//    printv(pos, cerr);

    vector<bool> now(n);
    while(true){

        vector<int> t;
        for(int i = 0; i < n; i++){
            if(pos[i] && !now[i]) t.eb(i);
        }

        if(t.size() < tmp){
            cout << "0\n" << flush;
            break;
        }

        cout << tmp << " ";
        for(int i = 0; i < tmp; i++) cout << t[i] + 1 << " ", now[t[i]] = true;
        cout << "\n" << flush;

//        printv(now, cerr);

        int x;
        cin >> x;
        x--;
        for(int i = x; i < x + tmp; i++) now[i % n] = false;
//        printv(now, cerr);

    }

    return 0;
}