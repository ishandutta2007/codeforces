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

int d[35000000];
int pref[35000000];
int b[500500];

ll cnt;
int s;

void add(int l, int r) {
    if (l<0) {
        add(0,r);
        add(l+s, s-1);
        return;
    }
    cnt += pref[r];
    if(l>0) cnt-=pref[l-1];
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi d2(1,1);
    forn(i,0,30) d2.pb(d2.back()*2);
    int n;
    scanf("%d\n", &n);
    readv(a,n);
    int ans = 0;
    forn(bit,0,25) {
        forn(i,0,d2[bit+1]) d[i] = 0;
        forn(i,0,d2[bit+1]) pref[i] = 0;
        s = d2[bit+1];
        forn(i,0,n) {
            b[i] = a[i]%d2[bit+1];
            d[b[i]]++;
        }
        pref[0] = d[0];
        forn(i,1,d2[bit+1]) pref[i] = pref[i-1] + d[i];
        cnt = 0;
        forn(i,0,n) {
            int l = d2[bit] - b[i];
            int r = d2[bit+1] - 1 - b[i];
            add(l, r);
            if((2*b[i])%s >= d2[bit]) cnt--;
        }
        cnt/=2;
        if(cnt%2) ans += d2[bit];
    }
    cout<<ans;
    
    
}