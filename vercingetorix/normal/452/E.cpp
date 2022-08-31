#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

struct state {
    int len, link,cnt[3];
    map<char,int> next;
};

#ifdef LOCAL
const int MAXLEN = 100;
#else
const int MAXLEN = 300500;
#endif

state st[MAXLEN*2];
int sz, last;

void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
    /*
     //   ,         :
     for (int i=0; i<MAXLEN*2; ++i)
     st[i].next.clear();
     */
}
int curs = 0;

void sa_extend (char c) {
    int cur = sz++;
    st[cur].cnt[curs] = 1;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string a;
    char c[300500];
    vs b;
    forn(i,0,3) {
        scanf("%s", c);
        b.pb(string(c));
        a += b[i];
        if(i != 2) a+=char('z'+1);
    }
    int len = 300500;
    forn(i,0,3) len = min(len, (int)b[i].size());
    int cut1 = b[0].size();
    int cut2 = b[0].size() + 1 + b[1].size();
    sa_init();
    forn(i,0,a.size()) {
        if(i == cut1 || i == cut2) curs++;
        sa_extend(a[i]);
    }
    vll ans(len+1,0);
    vpi ord;
    forn(i,1,sz) ord.pb(mp(st[i].len, i));
    srtrev(ord);
//    for(int i = sz - 1; i>0; i--) {
    for(auto op : ord) {
        int i = op.second;
        int curlen = st[i].len;
        int par = st[i].link;
        forn(it,0,3) st[par].cnt[it] += st[i].cnt[it];
        if(st[i].cnt[0] > 0 && st[i].cnt[1] > 0 && st[i].cnt[2] > 0) {
            ans[curlen] += ll(st[i].cnt[0])*st[i].cnt[2]%mod*st[i].cnt[1]%mod;
            ans[st[par].len] -= ll(st[i].cnt[0])*st[i].cnt[2]%mod*st[i].cnt[1]%mod;
        }
    }
    for(int i = len; i>0; i--) {
        ans[i-1] += ans[i];
    }
//    for(int i = sz - 1; i>0; i--) {
//        int curlen = st[i].len;
//        int par = st[i].link;
//        if(curlen <= len) ans[st[par].len] += ans[curlen];
//    }
//    forn(i,0, sz) {
//        printf("Vertex %d, len %d, link %d:\n", i, st[i].len, st[i].link);
//        printf("edges:");
//        for(auto x : st[i].next) printf(" %c %d;", x.first, x.second);
//        printf("\n");
//        printf("cnt %d %d %d\n", st[i].cnt[0], st[i].cnt[1], st[i].cnt[2]);
//    }
    forn(i,1,len+1) printf("%lld ", (ans[i]%mod+mod)%mod);
    
    
}