#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>
#include <array>

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
class streesum {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, 0);
    }
    
//    void push(int v) {
//        if (t[v] != 0) {
//            t[2*v]  += t[v];
//            t[2*v+1] += t[v];
//            t[v] = 0;
//        }
//    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += val;
        else {
//            push(v);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
//        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};
const int NPrimes = 2;
struct stolenhash{
    std::string s;
    std::array<uint32_t, NPrimes> primes;
    std::array<std::vector<uint32_t>, NPrimes> hashes;
    std::array<std::vector<uint32_t>, NPrimes> mults;
    
    void genPrimes() {
        for (int i = 0; i < NPrimes; i++) {
            int init = 100000000 + gen()%100000;
            int cur = init | 1;
            bool good;
            do {
                good = true;
                for (int j = 3; j * j <= cur; j++) {
                    if (cur % j == 0) {
                        cur += 2;
                        good = false;
                        break;
                    }
                }
            } while (!good);
            primes[i] = cur;
        }
    }
    
    void genHashes() {
        for (int i = 0; i < NPrimes; i++) {
            std::vector<uint32_t>& hash = hashes[i];
            std::vector<uint32_t>& mult = mults[i];
            hash.resize(s.length() + 1);
            mult.resize(s.length() + 1);
            mult[0] = 1;
            hash[0] = 0;
            int p = primes[i];
            for (int j = 0; j < s.length(); j++) {
                hash[j + 1] = ((hash[j] * 31) + (s[j] - 'a')) % p;
                mult[j + 1] = (mult[j] * 31) % p;
            }
        }
    }
    
    int getHash(int idx, int from, int to) {
        int res = (int) hashes[idx][to] - (int) (hashes[idx][from] * int64_t(mults[idx][to - from]) % primes[idx]);
        if (res < 0) {
            res += primes[idx];
        }
        return res;
    }
    
    pi getHash(int from, int to) {
        return mp(getHash(0, from, to), getHash(1, from, to));
    }
};

const int N = 200500;
class streemin {
public:
    vi t;
    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, N);
        pp = vi(4*n, N);
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == N) return;
        t[v] = min(t[v], pp[v]);
        if(tl != tr) {
            pp[2*v] = min(pp[2*v], pp[v]);
            pp[2*v+1] = min(pp[2*v+1] , pp[v]);
        }
        pp[v] = N;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] = min(pp[v], val);
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return N;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  min(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = min(t[v*2], t[v*2+1]);
        return ret;
    }
};

vector<int> z_function(string const& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

bool z_function(string const& s, int f, int to) {
//    int n = s.size();
    int n = to-f+1;
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[z[i]+f] == s[i+z[i]+f])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    forn(i,0,n) if(i+z[i]>=n) return true;
    return false;
}

int get_z(vector<int> const& z, int i) {
    if (0 <= i && i < (int)z.size())
        return z[i];
    else
        return 0;
}

//vector<pair<int, int>> repetitions;
int n;
streemin len[2];
streemin re;
int curlen = 0;
stolenhash sh;

void convert_to_repetitions(int shift, bool left, int cntr, int l, int k1, int k2) {
    int ll1 = max(1, l-k2);
    int rl1 = min(l, k1);
    if(left && rl1 == l) rl1--;
    if(left) {
        int posl = shift + cntr - rl1;
        int posr = shift + cntr - ll1;
        len[curlen].update(1, 0, n-1, posl, posr, 2*l);
    }
    else {
        int posl = shift + cntr - rl1 - l + 1;
        int posr = shift + cntr - ll1 - l + 1;
        len[curlen].update(1, 0, n-1, posl, posr, 2*l);
    }
}

vi q[N];

void find_repetitions(string s, int shift = 0) {
    int n = s.size();
    if (n == 1)
        return;
    
    int nu = n / 2;
    int nv = n - nu;
    string u = s.substr(0, nu);
    string v = s.substr(nu);
    string ru(u.rbegin(), u.rend());
    string rv(v.rbegin(), v.rend());
    
    find_repetitions(u, shift);
    find_repetitions(v, shift + nu);
    
    vector<int> z1 = z_function(ru);
    vector<int> z2 = z_function(v + '#' + u);
    vector<int> z3 = z_function(ru + '#' + rv);
    vector<int> z4 = z_function(v);
    
    for (int cntr = 0; cntr < n; cntr++) {
        int l, k1, k2;
        if (cntr < nu) {
            l = nu - cntr;
            k1 = get_z(z1, nu - cntr);
            k2 = get_z(z2, nv + 1 + cntr);
        } else {
            l = cntr - nu + 1;
            k1 = get_z(z3, nu + 1 + nv - 1 - (cntr - nu));
            k2 = get_z(z4, (cntr - nu) + 1);
        }
        if (k1 + k2 >= l) {
            convert_to_repetitions(shift, cntr < nu, cntr, l, k1, k2);
//            cout<<shift<<' '<<(cntr<nu)<<' '<<cntr<<' '<<l<<' '<<k1<<' '<<k2<<endl;
        }
    }
}
const int A = 400;
//int prehash[A][N];
vpi ev[N];
void try_split(string & s, int pos) {
    string u = s.substr(0, pos);
    string v = s.substr(pos);
    string ru(u.rbegin(), u.rend());
    string rv(v.rbegin(), v.rend());
    int nu = pos;
    int nv = n - pos;
    vector<int> z1 = z_function(ru);
    vector<int> z2 = z_function(v + '#' + u);
//    vector<int> z3 = z_function(ru + '#' + rv);
//    vector<int> z4 = z_function(v);
    for (int cntr = 0; cntr < pos; cntr++) {
//        int l, k1, k2;
//        if (cntr < pos) {
//            int l = nu - cntr;
            int k1 = get_z(z1, nu - cntr);
            int k2 = get_z(z2, nv + 1 + cntr);
//        }
        if(k1+k2 >= A && k2 > 0) {
            ev[cntr - k1].pb(mp(pos,pos+k2-1));
            ev[cntr+1].pb(mp(-pos, pos+k2-1));
        }
    }
}

int qn;

int l[N];
int r[N];
int ans[N];
int cnt[26][N];
vi divs[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    sh.genPrimes();
    forn(i,1,N) {
        divs[i].pb(1);
        for(int k = 2; k*k<=i; k++) {
            if(i%k == 0) {
                divs[i].pb(k);
                if(k*k<i) divs[i].pb(i/k);
            }
        }
    }
    scanf("%d\n", &n);
    char c[200500];
    scanf("%s", c);
    string s(c);
    sh.s = s;
    sh.genHashes();
    forn(i,0,n) {
        if(i>0) forn(j,0,26) cnt[j][i] = cnt[j][i-1];
        cnt[s[i]-'a'][i]++;
    }
    scanf("%d", &qn);
    forn(it,0,2) len[it].build(n, 1, 0, n-1);
    forn(i,0,qn) {
        ans[i] = 5;
        scanf("%d", &l[i]);
        scanf("%d", &r[i]);
        l[i]--;
        r[i]--;
        vi ccur(26,0);
        int can = 0;
        forn(j,0,26) {
            ccur[j] = cnt[j][r[i]];
            if(l[i] > 0) ccur[j] -= cnt[j][l[i]-1];
            if(ccur[j] > 1) can = 1;
        }
        if(can) {
            ans[i] = 4;
            if(ccur[s[l[i]] - 'a'] > 1) ans[i] = 3;
            if(ccur[s[r[i]] - 'a'] > 1) ans[i] = 3;
            int dd = r[i] - l[i] + 1;
            for(auto d : divs[dd]) {
                if(sh.getHash(l[i], 1+r[i]-d) == sh.getHash(l[i]+d, 1+r[i])) {
                    ans[i] = 1;
                    break;
                }
            }
        }
        else ans[i] = -1;
    }
    find_repetitions(s);
    re.build(n, 1, 0, n-1);
    forn(i,0,n) {
        int ml = len[0].get(1, 0, n-1, i, i);
        if (ml < N) re.update(1, 0, n-1, i, i, i + ml - 1);
    }
    curlen = 1;
    reverse(all(s));
    find_repetitions(s);
    forn(i,0,qn) if(ans[i] > 2){
        if(len[0].get(1, 0, n-1, l[i], l[i]) <= r[i] - l[i] + 1) ans[i] = min(ans[i], 2);
        else if(len[1].get(1, 0, n-1, n-1-r[i], n-1-r[i]) <= r[i] - l[i] + 1) ans[i] = min(ans[i], 2);
        else if(re.get(1, 0, n-1, l[i], r[i]) <= r[i]) ans[i] = min(ans[i], 3);
    }
    forn(i,0,qn) {
        if(ans[i] > 2) {
            int ql = r[i]-l[i]+1;
            forn(pl,1,min(A, ql)) {
                if(sh.getHash(l[i], l[i] + pl) == sh.getHash(r[i]-pl+1, r[i]+1)) {
                    ans[i] = 2;
                    break;
                }
            }
        }
    }
    int badq = 0;
    forn(i,0,qn) {
        if(ans[i] > 2) {
            q[l[i]].pb(i);
            badq++;
        }
    }
    reverse(all(s));
    streesum st;
    if(badq > 1000) {
        int dietimer = 100;
        int die = dietimer;
        for(int pos = A; pos < n; pos += A) {
            try_split(s, pos);
            if(--die == 0 || pos + A >= n) {
                die = dietimer;
                st.build(n, 1, 0, n-1);
                for(int f = 0; f <= n; f++) {
                    for(auto & x : ev[f]) {
                        if(x.first > 0) {
                            st.update(1, 0, n-1, x.first, x.second, 1);
                        }
                        else {
                            st.update(1, 0, n-1, -x.first, x.second, -1);
                        }
                    }
                    ev[f].clear();
                    for(auto i : q[f]) {
                        if(st.get(1, 0, n-1, r[i]) > 0) ans[i] = 2;
                    }
                }
            }
        }
    }
    else {
        forn(i,0,qn) {
            if(ans[i] > 2) {
                if(z_function(s, l[i], r[i])) ans[i] = 2;
            }
        }
    }
//    try_split(s, 5);
    
    forn(i,0,qn) printf("%d\n", ans[i]);
    
}