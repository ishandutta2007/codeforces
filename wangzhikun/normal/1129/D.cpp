#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

#warning change B
const int B = 100;
const int nax = 2e5 + 5;
int offset[nax/B];
int cnt[nax/B][B+2];
int his[nax];

const int mod = 998244353;

void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    //~ vector<int> cnt(n + 1);
    
    vector<int> dp(B + n + 2);
    dp[1] = 1;
    
    auto ogarnij = [&](int who) {
        for(int i = 0; i <= B; ++i) {
            cnt[who][i] = 0;
        }
        int small = INT_MAX;
        for(int i = max(1, who * B); i < (who + 1) * B; ++i) {
            small = min(small, his[i]);
        }
        offset[who] += small;
        for(int i = max(1, who * B); i < (who + 1) * B; ++i) {
            his[i] -= small;
            //~ debug() << imie(i) imie(who) imie(his[i]);
            add_self(cnt[who][his[i]], dp[i]);
        }
        for(int i = 1; i <= B; ++i) {
            add_self(cnt[who][i], cnt[who][i-1]); // prefix sum
        }
    };
    
    auto add = [&](int L, int R, int x) {
        //~ debug() << "------------> " imie(L) imie(R) imie(x);
        int left = L / B;
        int right = R / B;
        for(int i = left + 1; i < right; ++i) {
            offset[i] += x;
        }
        for(int i = L; i <= R && i / B == left; ++i) {
            his[i] += x;
        }
        ogarnij(left);
        if(left != right) {
            for(int i = R; i / B == right; --i) {
                his[i] += x;
            }
            ogarnij(right);
        }
    };
    
    ogarnij(0);
    
    vector<int> last(n + 1), sec_last(n + 1);
    for(int me = 1; me <= n; ++me) {
        //~ debug();
        int x;
        scanf("%d", &x);
        if(last[x]) {
            add(sec_last[x] + 1, last[x], -1);
        }
        add(last[x] + 1, me, 1);
        sec_last[x] = last[x];
        last[x] = me;
        
        //~ for(int i = 0; i <= me; ++i) {
            //~ debug() << imie(i) imie(offset[i/B]) imie(his[i]);
        //~ }
        //~ for(int who = 0; who <= me / B; ++who) {
            //~ for(int k = 0; k <= B; ++k) {
                //~ debug() << imie(who) imie(offset[who]) imie(k) imie(cnt[who][k]);
            //~ }
        //~ }
        
        int Z = 0;
        for(int who = 0; who <= me / B; ++who) {
            int up_to = min(k - offset[who], B);
            if(up_to >= 0) {
                add_self(Z, cnt[who][up_to]);
            }
        }
        dp[me+1] = Z;
        ogarnij((me + 1) / B);
        //~ for(int i = 1; i <= me; ++i) {
            //~ if(cnt[i] <= k) {
                //~ add_self(dp[me+1], dp[i]);
            //~ }
        //~ }
    }
    //~ debug() << imie(dp);
    printf("%d\n", dp[n+1]);
}