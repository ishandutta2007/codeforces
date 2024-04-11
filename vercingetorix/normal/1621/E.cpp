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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n,&m);
        readv(a,n);
        srtrev(a);
        while(a.size() > m) a.pop_back();
        reverse(all(a));
        vvi p;
        vpll q;
        vll ss;
        forn(i,0,m) {
            int k;
            read(k);
            readv(b,k);
            ll sum = 0;
            for(auto x : b) sum += x;
            ss.pb(sum);
            ll need = (sum + k-1)/k;
            q.pb(mp(need, i));
            p.pb(b);
        }
        srt(q);
        vi loc(m);
        forn(i,0,m) loc[q[i].second] = i;
        vi pref(1,0);
        vi prefl(1,0);
        vi prefr(1,0);
        forn(i,0,m) {
            pref.pb(pref.back());
            prefl.pb(prefl.back());
            prefr.pb(prefr.back());
            if(a[i] >= q[i].first) pref.back()++;
            if(i==0 || a[i-1] >= q[i].first) prefl.back()++;
            if(i==m-1 || a[i+1] >= q[i].first) prefr.back()++;
        }
        string ans;
        forn(i,0,m) {
            int pos = loc[i];
            int k = p[i].size();
            ll need = q[pos].first;
            for(auto x : p[i]) {
                ll nsum = ss[i] - x;
                ll nneed = (nsum + k-2)/(k-1);
                int can = 1;
                int npos = lower_bound(all(q), mp(nneed, 0ll)) - q.begin();
                if(npos > pos) npos--;
                int l = min(npos, pos);
                int r = max(npos, pos);
                if(pref[l] != l) can = 0;
                if(pref[m] - pref[r+1] != m-r-1) can = 0;
                if(a[npos] < nneed) can = 0;
                if(pos < npos) {
                    if(prefl[npos+1] - prefl[pos+1] != npos-pos) can = 0;
                }
                if(pos > npos) {
                    if(prefr[pos+1] - prefr[npos+1] != pos-npos) can = 0;
                }
                if(can) ans.pb('1');
                else ans.pb('0');
            }
        }
        printf("%s\n", ans.c_str());
    
    }
    
    
}