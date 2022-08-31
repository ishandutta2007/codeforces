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
const int maxlen = 300500;
const int alphabet = 2;
int p[maxlen], cnt[maxlen], c[20][maxlen];
int pn[maxlen];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    char cc[300500];
    scanf("%s", cc);
    string s(cc);
    int q;
    scanf("%d", &q);
    vi z;
    forn(i,0,n) if(s[i] == '0') z.pb(i);
    int k = z.size();
    vi a;
    forn(i,0,k-1) {
        a.pb((z[i+1]-z[i])%2);
    }
    n = k-1;
    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i)
        ++cnt[a[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[a[i]]] = i;
    c[0][p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (a[p[i]] != a[p[i-1]])  ++classes;
        c[0][p[i]] = classes-1;
    }
    
    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[c[h][pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[h][pn[i]]]] = pn[i];
        c[h+1][p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[h][p[i]] != c[h][p[i-1]] || c[h][mid1] != c[h][mid2])
                ++classes;
            c[h+1][p[i]] = classes-1;
        }
    }
    
    
    forn(i,0,q) {
        int l1,l2,len;
        scanf("%d %d %d", &l1, &l2, &len);
        l1--; l2--;
        auto it1 = lower_bound(all(z), l1);
        auto it2 = lower_bound(all(z), l2);
        int c01 = lower_bound(all(z), l1+len) - it1;
        int c02 = lower_bound(all(z), l2+len) - it2;
        if(c01!=c02) {
//            cout<<"No\n";
            printf("No\n");
            continue;
        }
        if(c01>0 && (*it1 - l1)%2 != (*it2 - l2)%2) {
//            cout<<"No\n";
            printf("No\n");
            continue;
        }
        int f1 = it1-z.begin();
        int f2 = it2-z.begin();
        int lt = c01-1;
        if(lt > 0) {
            int d2 = 1;
            int deg = 0;
            while(d2*2<=lt) {
                d2*=2;
                deg++;
            }
            if(c[deg][f1] != c[deg][f2] || c[deg][f1+lt-d2] != c[deg][f2+lt-d2]) {
//                cout<<"No\n"
                printf("No\n");
                continue;
            }
            
        }
        printf("Yes\n");
//        cout<<"Yes\n";
        
    }
    
}