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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int N = 200000;
int mindiv[N+1];
vector<ll> pr;
vi isp(N, 0);

vi getall(int m) {
    if(m==1) return vi();
    int pp =mindiv[m];
    while(m%pp == 0) m/=pp;
    vi ret = getall(m);
    ret.pb(pp);
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    vvi ad(N+1);
    
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
    forn(affa,0,t) {
        vi ans(N+1,0);
        int best = 0;
        vi cnt(N+1,0);
    
        int n;
        read(n);
        readv(a,n);
        sort(all(a));
        for(auto x : a) cnt[x]++;
        forn(i,1,a.back()+1) {
            auto l = getall(i);
            for(auto p : l) ans[i] = max(ans[i], ans[i/p]);
            ans[i] += cnt[i];
            best = max(best, ans[i]);
        }
        cout<<n-best<<endl;
        
    }
    
}