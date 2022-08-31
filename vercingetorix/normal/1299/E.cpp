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

//int get(int n) {
//    if(n<=1) return 0;
//    int ret = 0;
//    if(n%2) {
//        ret += --n;
//    }
//    ret += 2*n;
//    ret += 2*get((n-2)/2);
//    return ret;
//}

int get(int n) {
    if(n<=2) return 0;
    int ret = 0;
    if(n%4 == 2) return n+get(n-2);
    return n+2*get(n/2);
    //    int ret = n;
    //    if(n <= 2) return 0;
    //    int ret = 2*(n-1);
    //    int a = (n-2)/2;
    //    int b = n-2-a;
    //    ret += get(a) + get(b);
    //    if(a>1) ret++;
    //    if(b>1) ret++;
    //    return ret;
}

//int w[888];
//int ans[888];
vi d[10][512];
int f[10][512];
int d2[10];

int ask(const vi & a) {
    printf("? %d", (int)a.size());
    for(auto x : a) printf(" %d", x+1);
    printf("\n");
    fflush(stdout);
    int ret;
    read(ret);
    return ret;
}

int ask1(const vi & a, int del) {
    printf("? %d", (int)a.size()-1);
    for(auto x : a) if(x != del) printf(" %d", x+1);
    printf("\n");
    fflush(stdout);
    int ret;
    read(ret);
    return ret;
}
const int A = 800;
int r[10][A];
int ans[A];
int w[A];
int n;
vi rdone;
void findlr() {
    vi full;
    forn(i,0,n) full.pb(i);
    vi res;
    forn(i,0,n) {
        if(ask1(full, i)) res.pb(i);
        if(res.size() == 2) break;
    }
    ans[res[0]] = 0;
    w[0] = res[0];
    ans[res[1]] = n-1;
    w[n-1] = res[1];
}

void solve2() {
    forn(i,0,n) {
        if(ans[i] != -1) r[2][i] = ans[i]%2;
        else r[2][i] = 1-ask({w[0], i});
    }
    rdone.pb(2);
}

void findnext(int k) {
    if(k>=n || w[k] != -1) return;
    vi full;
    forn(i,0,n) {
        if(ans[i] == -1) full.pb(i);
    }
    if(k%2==0) full.pb(w[n-1]);
    for(auto ind : full) {
        int good = 1;
        for(auto m : rdone) if(r[m][ind] != k%m) good = 0;
        if(good && ask1(full, ind)) {
            ans[ind] = k;
            w[k] = ind;
            break;
        }
    }
}

void solvemod(int m) {
    if(m>=n) return;
    vi full;
    int sum = 0;
    forn(i,0,m) {
        full.pb(w[i]);
        sum+=i;
    }
    sum%=m;
    forn(i,0,n) if(ans[i] == -1) {
        full.pb(i);
        vi val;
        forn(j,0,m) {
            int bad = 0;
            for(auto m2 : rdone) {
                int d = gcd(m,m2);
                if(r[m2][i] % d != j%d) bad = 1;
            }
            if(bad) continue;
            val.pb(j);
        }
        int found = 0;
        forn(it,0,val.size() - 1) {
            int j = val[it];
            if(ask1(full, w[j])) {
                r[m][i] = (j+m-sum)%m;
                found = 1;
                break;
            }
        }
        if(found == 0) {
            r[m][i] = (val.back()+m-sum)%m;
        }
        full.pop_back();
    }
    else r[m][i] = ans[i]%m;
    rdone.pb(m);
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
//    int n;
    scanf("%d", &n);
    forn(i,0,A) {
        forn(j,0,10) r[j][i] = -1;
        ans[i] = -1;
        w[i] = -1;
    }
    findlr();
    solve2();
    findnext(1);
    findnext(2);
    solvemod(3);
    findnext(3);
    solvemod(4);
    findnext(4);
    solvemod(5);
    findnext(5);
    findnext(6);
    solvemod(7);
    findnext(7);
    solvemod(8);
    forn(i,0,n) if(ans[i] == -1) {
        forn(cand,0,n) {
            int good = 1;
            for(auto m : rdone) if(cand%m != r[m][i]) good = 0;
            if(good) {
                ans[i] = cand;
                break;
            }
        }
    }
    printf("!");
    if(ans[0] + 1 > n/2) {
        forn(i,0,n) ans[i] = n-1-ans[i];
    }
    forn(i,0,n) printf(" %d", ans[i]+1);
    printf("\n");
    
    
}