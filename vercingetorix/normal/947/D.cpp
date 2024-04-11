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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[100500];
    scanf("%s", c);
    string s(c);
    scanf("%s", c);
    string t(c);
    vi sb,tb;
    sb.pb(-1);
    tb.pb(-1);
    vi cs;
    int sum = 0;
    forn(i,0,s.size()) {
        if(s[i] != 'A') {
            sb.pb(i);
            sum ++;
        }
        cs.pb(sum);
    }
    sum = 0;
    vi ct;
    forn(i,0,t.size()) {
        if(t[i] != 'A') {
            tb.pb(i);
            sum ++;
        }
        ct.pb(sum);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int ls,rs,lt,rt;
        scanf("%d %d %d %d", &ls, &rs, &lt, &rt);
        ls--;
        rs--;
        lt--;
        rt--;
        int ns = cs[rs];
        if(ls > 0) ns -= cs[ls-1];
        int nt = ct[rt];
        if(lt > 0) nt -= ct[lt-1];
        auto it = upper_bound(all(sb), rs);
        it --;
        int nas = rs - *it;
        if(nas > rs-ls+1) nas = rs-ls+1;
        it = upper_bound(all(tb), rt);
        it --;
        int nat = rt - *it;
        if(nat > rt-lt+1) nat = rt-lt+1;
        if(nat > nas) {
            printf("0");
            continue;
        }
        if(nas == rs-ls+1 && nat != rt-lt+1) {
            if(nat == nas) {
                printf("0");
                continue;
            }
            else {
                nas = nat;
                ns+=2;
            }
        }
        if(nas%3!=nat%3) ns+=2;
        if(ns > nt || ns%2 != nt%2) printf("0");
        else printf("1");
//        cout<<ns<<' '<<nt<<' '<<nas<<' '<<nat<<endl;
    }
    
    
}