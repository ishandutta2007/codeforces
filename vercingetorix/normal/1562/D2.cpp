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
vi pref;
void go(int l, int r) {
    int dif = pref[r] - pref[l-1];
    int l1=l-1;
    int r1=r;
    while(r1-l1>1) {
        int m1 = (r1+l1)/2;
        if(abs(pref[m1]-pref[l-1]) < abs(pref[m1]-pref[r])) {
            l1 = m1;
        }
        else r1=m1;
    }
    printf("%d\n", r1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[300500];
    while(t--) {
        int n, q;
        scanf("%d %d\n", &n,&q);
        scanf("%s",c);
        int cur = 0;
        int tot = 0;
        pref.clear();
        int sg = 1;
        pref.pb(0);
        forn(i,0,n) {
            if(c[i]=='+') tot+=sg;
            else tot-=sg;
            sg = -sg;
            pref.pb(tot);
        }
        while(q--) {
            int l,r;
            scanf("%d %d", &l, &r);
            int dif = pref[r] - pref[l-1];
            if(dif == 0) printf("0\n");
            else if(dif%2==0) {
                printf("2\n");
                printf("%d ", l);
                go(++l,r);
            }
            else {
                printf("1\n");
                go(l,r);
            }
        }
    }
    
    
}