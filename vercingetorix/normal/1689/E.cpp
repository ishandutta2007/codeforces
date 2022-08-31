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

const int A = 2005;
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

int n;
int ans;
vi a;
bool check() {
    forn(i,0,n) make_set(i);
    forn(bit,0,30) {
        int d2 = 1<<bit;
        int last  = -1;
        forn(i,0,n) if(a[i]&d2) {
            if(last != -1) union_sets(last, i);
            last = i;
        }
    }
    forn(i,0,n) if(find_set(i) != find_set(0)) return false;
    return true;
}

void win() {
    printf("%d\n", ans);
    for(auto x : a) printf("%d ", x);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        
        scanf("%d", &n);
        a.resize(n);
        forn(i,0,n) scanf("%d", &a[i]);
        ans = 0;
        forn(i,0,n) if(a[i] == 0) {
            a[i]++;
            ans++;
        }
        if(check()) {
            win();
            continue;
        }
        int done = 0;
        forn(i,0,n) {
            ans++;
            a[i]++;
            if(check()) {
                win();
                done = 1;
                break;
            }
            a[i]-=2;
            if(check()) {
                win();
                done = 1;
                break;
            }
            a[i]++;
            ans--;
        }
        if(done) continue;
        int bit = 30;
        while(1) {
            bit--;
            int d2 = 1<<bit;
            vi ind;
            forn(i,0,n) if(a[i] % d2 == 0) ind.pb(i);
            if(!ind.empty()) {
                a[ind[0]]--;
                a[ind[1]]++;
                ans+=2;
                win();
                break;
            }
        }
    }
    
    
}