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
    const int N = 200;
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int t;
    read(t);
    char  c[500];
    while(t--) {
        int k;
        scanf("%d\n", &k);
        scanf("%s", c);
        pi ans = mp(4,-1);
        
        forn(i,0,k) {
            int cand = c[i]-'0';
            if(cand == 1) ans = min(ans, mp(1,1));
            for(auto x : pr) if(cand > x && cand%x==0) ans = min(ans, mp(1,cand));
        }
        forn(i,0,k) forn(j,i+1,k) {
            int cand = int(c[i]-'0')*10+int(c[j]-'0');
            for(auto x : pr) if(cand > x && cand%x==0) ans = min(ans, mp(2,cand));
        }
        if(ans.first > 3) {
            forn(i,0,k) {forn(j,i+1,k) forn(l,j+1,k){
                int cand = int(c[i]-'0')*100+int(c[j]-'0')*10+int(c[l]-'0');
                for(auto x : pr) if(cand > x && cand%x==0) ans = min(ans, mp(3,cand));
            }
            if(ans.first==3) break;
            }
        }
        printf("%d\n%d\n", ans.first, ans.second);
        
    }
    
    
}