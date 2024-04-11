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
    int t;
    scanf("%d\n", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a, n);
        vi b = a;
        sort(all(b));
        map<int, int> prev,nx;
        prev[b[0]] = -1;
        nx[b.back()] = -1;
        forn(i,1,n) {
            if(b[i] != b[i-1]) prev[b[i]] = b[i-1];
            if(b[i] != b[i-1]) nx[b[i-1]] = b[i];
        }
        int ans = 0;
        map<int, int> liscomp;
        map<int, vi> pos;
        forn(i,0,n) pos[a[i]].pb(i);
        map<int, int> last;
        forn(i,0,n) last[a[i]] = -1;
        vi lm(n,-1);
        vi clm(n,0);
        forn(i,0,n) {
            if(pos[a[i]].back() == i) {
                lm[i] = pos[a[i]][0];
                clm[i] = (int)pos[a[i]].size();
                int pr = prev[a[i]];
                if(pr != -1 && pos[pr].back() < pos[a[i]][0]) {
                    lm[i] = lm[pos[pr].back()];
                    clm[i] = clm[pos[pr].back()] + int(pos[a[i]].size());
                }
                int nxt = nx[a[i]];
                int cand = clm[i];
                if(nxt!=-1) {
                    auto itr = lower_bound(all(pos[nxt]), i);
                    cand += int(pos[nxt].end() - itr);
                }
                pr = prev[a[lm[i]]];
                if(pr!=-1) {
                    auto itl = lower_bound(all(pos[pr]), lm[i]);
                    cand += int(itl - pos[pr].begin());
                }
                ans = max(ans, cand);
            }
            int pr = prev[a[i]];
            auto it = lower_bound(all(pos[a[i]]), i);
            int cand = pos[a[i]].end() - it;
            if(pr!=-1) {
                auto itl = lower_bound(all(pos[pr]), i);
                cand += int(itl - pos[pr].begin());
            }
            ans = max(ans, cand);
            
        }
        cout<<n-ans<<endl;
    }
    
}