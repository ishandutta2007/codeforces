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

inline int my_getchar() {
    const int N = 1<<20;
    static char buf[N];
    static char *p = buf , *end = buf;
    if(p == end) {
        if((end = buf + fread(buf , 1 , N , stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

inline int readint(int &x) {
    static char c , neg;
    while((c = my_getchar()) < '-') {
        if(c == EOF) return 0;
    }
    neg = (c == '-') ? -1 : 1;
    x = (neg == 1) ? c - '0' : 0;
    while((c = my_getchar()) >= '0') x = (x << 3) + (x << 1) + (c - '0');
    x *= neg;
    return 1;
}

// output optimize
const int kBufSize = 524288;
char inbuf[kBufSize];
char buf_[kBufSize]; size_t size_;
inline void Flush_() { write(1, buf_, size_); size_ = 0; }
inline void CheckFlush_(size_t sz) { if (sz + size_ > kBufSize) Flush_(); }

inline void PutInt(int a) {
    static char tmp[22] = "01234567890123456789\n";
    CheckFlush_(10);
    if(a < 0){
        *(buf_ + size_) = '-';
        a = ~a + 1;
        size_++;
    }
    int tail = 20;
    if (!a) {
        tmp[--tail] = '0';
    } else {
        for (; a; a /= 10) tmp[--tail] = (a % 10) ^ '0';
    }
    memcpy(buf_ + size_, tmp + tail, 21 - tail);
    size_ += 21 - tail;
}


int check(int n, int x, vector<int>& a, vector<int>& b){
    vector<pii> tmp;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) tmp.eb(mp(a[i], b[i]));
    }
    lsort(tmp);
    int lst = x;
    for(pii i : tmp){
        if(i.S != lst || i.F <= x) return MAX;
        lst = i.F;
    }
    return tmp.size();
}

int main(){
    StarBurstStream

    int T;
    readint(T);
    while(T--){

        int n, x;
        readint(n);
        readint(x);

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            readint(a[i]);
        }

        vector<int> tmp = a;
        lsort(tmp);
        int ans = check(n, x, a, tmp);
        for(int i = 0; i < n; i++){
            tmp = a;
            tmp[i] = x;
            lsort(tmp);
            ans = min(ans, check(n, x, a, tmp));
        }
        if(ans == MAX) ans = -1;
        PutInt(ans);
    }

    Flush_();

    return 0;
}