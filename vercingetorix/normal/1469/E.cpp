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
#include <array>
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
    int len, link;
    array<int, 2> next = {0,0};
};
#ifdef LOCAL
const int MAXLEN = 30;
#else
const int MAXLEN = 1000000;
#endif
state st[MAXLEN*2];
int sz, last;

void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
//     for (int i=0; i<MAXLEN*2; ++i)
//     st[i].next.clear();
}
void sa_extend (int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next[c]; p=st[p].link)
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

vi cur;
int found = 0;
int n,k;

void dfs(int v) {
    if(cur.size() == k) return;
    for(int to = 1; to>=0; to--) {
        if(found) return;
        if(st[v].next[to] == 0) {
            cur.pb(to);
            found = 1;
            return;
        }
        else {
            cur.pb(to);
            dfs(st[v].next[to]);
            if(found) return;
            cur.pop_back();
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[1000500];
    forn(ifa,0,ta) {
        scanf("%d %d\n", &n, &k);
        scanf("%s", c);
        sa_init();
        forn(i,0,n) sa_extend(c[i]-'0');
        found = 0;
        cur.clear();
        dfs(0);
        if(found) {
            while(cur.size() < k) cur.pb(1);
            string ans ;
            forn(i,0,k) ans.pb('0' + (1-cur[i]));
            printf("YES\n");
            printf("%s\n", ans.c_str());
        }
        else printf("NO\n");
        forn(i,0,2*n) st[i].next = {0,0};
    }
    
    
}