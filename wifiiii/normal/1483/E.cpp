#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<size_t T>
void __print(const bitset<T> &x) {cerr << '\"' << x << '\"';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define D(x...) cerr << "[" << #x << "] = ["; _print(x)

const ll inf = 1e14;
struct test {
    ll M, cur;
    int cnt = 0;
    void init() {
        M = mrand() % (inf / 2) + inf / 2;
//        M = 32;
        cur = 1;
        cnt = 0;
        D(M);
    }
    string ask(ll x) {
//        D(cur,x);
        ++cnt;
        if(cnt > 105) assert(0);
        if(x <= M) {
            cur += x;
            return "Lucky!";
        }
        cur -= x;
        if(cur < 0) return "Fired!";
        return "Fraudster!";
    }
    void submit(ll x) {
        assert(x == M);
        D("ac", M, cnt);
    }
}mytest;
int cnt = 0;
int ask(ll x) {
    cout << "? " << x << endl;
    ++cnt;
//    string ret = mytest.ask(x); // debug
    string ret;
    cin >> ret;
    assert(ret[2] != 'r');
    if(ret[0] == 'L') return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cnt = 0;
//        mytest.init();
        ll cur = 1, lo = 0, hi = 0;
        while(1) {
            int p = ask(cur);
            if(p == 0) {
                cur = 0;
                break;
            } else {
                cur = cur * 2;
                lo = hi + 1;
                hi = cur - 1;
            }
            if(cur > inf) break;
        }
        hi = min(hi, inf);
        while(lo < hi) {
            ll mid = lo + (hi - lo) / 3.23;
//            if(hi - lo <= 10000) mid = lo + (hi - lo) / 2.33;
            if(cur >= hi * 3) mid = (lo + hi) / 2;
            if(hi - lo + 1 + (cur < lo + 1) + (cur == 0) <= 105 - cnt) {
//                D(lo,hi,mytest.cur,mytest.M);
                while(cur < lo + 1) {
                    assert(ask(lo));
                    cur += lo;
                }
                for(ll i = lo + 1; i <= hi + 1; ++i) {
                    if(i > inf) {
                        lo = hi = inf;
                        break;
                    }
                    if(!ask(i)) {
                        lo = hi = i - 1;
                        break;
                    }
                }
                break;
            }
            while(cur <= mid) {
                assert(ask(lo));
                cur += lo;
            }
            if(ask(mid)) lo = mid, cur += mid;
            else hi = mid - 1, cur -= mid;
//            D(lo,hi,mid,mytest.cur,cnt,t);
        }
        cout << "! " << lo << endl;
//        mytest.submit(lo);
    }
}