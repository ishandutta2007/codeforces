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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    char c[300500];
    scanf("%d\n", &n);
    scanf("%s", c);
    string s(c);
    vi bal(n, 0);
    int cur = 0;
    int best = 0;
    forn(i,0,n) {
        if(s[i] == '(') cur++;
        else cur--;
        bal[i] = cur;
        if(bal[best] >= bal[i]) best = i;
    }
    
    if(cur != 0) {
        printf("0\n");
        printf("1 1\n");
        exit(0);
    }
    vi lows;
    forn(i,0,n) if(bal[i] == bal[best]) lows.pb(i);
    int len = lows.size();
    int ans = lows.size();
    pi q = mp(0,0);
    forn(i,0,lows.size()) {
        int r = lows[(i+1)%int(lows.size())];
        int l = (lows[i] + 1)%n;
        if(r == (l+1)%n) continue;
        int m = l;
        int clow = 0;
        vi lp;
        while(1) {
            
            if(m==r) break;
            if(bal[m] == bal[best] + 1) {
                lp.pb(m);
                clow++;
            }
            m = (m+1)%n;
        }
        if(clow > ans) {
            ans = clow;
            q = mp(l,r);
        }
        int k = lp.size();
        forn(j,0,k-1) {
            int r1 = lp[j+1];
            int l1 = (lp[j] + 1)%n;
            int m1 = l1;
            int ckeep = 0;
            while(1) {
                
                if(m1==r1) break;
                if(bal[m1] == bal[best] + 2) {
                    ckeep ++;
                }
                m1 = (m1+1)%n;
            }
            if(ckeep + len > ans) {
                ans = ckeep + len;
                q = mp(l1,r1);
            }
        }
    }
    cout<<ans<<endl;
    cout<<q.first+1<<' '<<q.second+1;
}