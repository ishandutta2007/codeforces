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
const int A = 1100000;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
int cnt[1100500];
set<int> w[1100500];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    int n;
    scanf("%d", &n);
    vi a(n), b(n);
    forn(i,0,n) scanf("%d %d", &a[i], &b[i]);
    int pt = 20;
    while(1) {
        forn(i,0,n) {
            a[i]%=d2[pt];
            b[i]%=d2[pt];
        }
        forn(i,0,n) {
            make_set(a[i]);
            make_set(b[i]);
        }
        forn(i,0,n) {
            cnt[a[i]]++;
            cnt[b[i]]++;
            union_sets(a[i], b[i]);
        }
        int can = 1;
        forn(i,0,n) {
            if(find_set(a[i]) != find_set(a[0])) can = 0;
            if(find_set(b[i]) != find_set(a[0])) can = 0;
        }
        forn(i,0,d2[pt]) if(cnt[i]%2 != 0) {
            can = 0;
        }
        if(can) {
            vi val;
            forn(i,0,n) {
                val.pb(a[i]);
                val.pb(b[i]);
            }
            printf("%d\n", pt);
            vi vis(n,0);
            forn(i,0,n) {
                w[a[i]].insert(i);
                w[b[i]].insert(i);
            }
            vpi l;
            deque<pi> r;
            r.pb(mp(0, 0));
            while(!r.empty()) {
                while(!w[val[r[0].first]].empty()) {
                    auto it = w[val[r[0].first]].begin();
                    int i = *it;
                    w[a[i]].erase(i);
                    w[b[i]].erase(i);
                    if(a[i] == val[r[0].first]) r.push_front(mp(2*i+1, 2*i));
                    else r.push_front(mp(2*i, 2*i+1));
                }
                l.pb(r.front());
                r.pop_front();
            }
            l.pop_back();
            for(auto x : l) printf("%d %d ", x.first+1, x.second+1);
            break;
        }
        forn(i,0,n) {
            cnt[a[i]%d2[pt]]=0;
            cnt[b[i]%d2[pt]]=0;
        }
        pt--;
    }
    
}