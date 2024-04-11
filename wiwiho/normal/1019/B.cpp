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

int n;

vector<int> tmp;
int cnt = 0;

int query(int i){
    if(tmp[i] != -MAX) return tmp[i];
    cnt += 2;
    i %= n;
    cout << "? " << i + 1 << "\n" << flush;
    int r1;
    cin >> r1;
    i += n / 2;
    i %= n;
    cout << "? " << i + 1 << "\n" << flush;
    int r2;
    cin >> r2;
    tmp[i] = r1 - r2;
    return r1 - r2;
}

int ans(int a){
    if(a != -1) a = a % n + 1;
    cout << "! " << a << "\n" << flush;
    exit(0);
}

int main(){
    StarBurstStream

    cin >> n;
    tmp.resize(n, -MAX);

    int t = query(0);
    int l = 0;
    if(t == 0){
        ans(l);
    }
    if(t > 0) l += n / 2;

    if(t % 2 != 0){
        ans(-1);
    }

    int r = l + n / 2;
    while(l < r){
        int m = (l + r) / 2;
        t = query(m);
        if(t == 0) ans(m);
        else if(t < 0) l = m + 1;
        else r = m - 1;
    }

    ans(l);

    return 0;
}