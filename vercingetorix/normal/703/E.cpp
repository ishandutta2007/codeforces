#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <bitset>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

ll d[40][30000];
bitset<1000> last[40][30000];
ll a[1100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 1000000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    
    int n;
    ll k;
    cin>>n>>k;
    forn(i,0,n) cin>>a[i];
    vll div;
    for(ll i= 1; i<=1000000; i++) {
        if(i*i >= k) {
            if(i*i==k) div.pb(i);
            break;
        }
        if(k%i == 0) {
            div.pb(i);
            div.pb(k/i);
        }
    }
    int mind = 0;
    if(k==1) {
        forn(i,0,n) {
            if(a[i]<a[mind]) mind=i;
        }
        cout<<1<<endl<<mind+1;
        return 0;
    }
    int dmax = 0;
    ll K=k;
    for(auto pr:p) {
        while(K%pr == 0) {
            K/=pr;
            dmax++;
        }
    }
    if(K>1) dmax++;
    ll INF = 100000000000140000;
    sort(all(div));
    map<ll, int> ord;
    forn(i,0,div.size()) ord[div[i]] = i;
    forn(i,0,dmax+1) forn(j,0,div.size()) d[i][j] = INF;
//    forn(i,0,dmax+1) forn(j,0,div.size()) last[i][j] = -1;
//    vvi last(40, vi(div.size(), -1));
    d[0][0] = 0;
    vll b(n);
    forn(i,0,n) b[i] = gcd(a[i],k);
    forn(i,0,n) {
        vi to(div.size(),0);
        forn(j,0,div.size()) {
            to[j] = ord[gcd(div[j] * b[i], k)];
        }
        for(int num = dmax-1; num >=0; num--) {
            forn(j,0,div.size()) {
                if(to[j] == j) continue;
                if(d[num+1][to[j]] > d[num][j] + a[i]) {
                    d[num+1][to[j]] = d[num][j] + a[i];
                    last[num+1][to[j]] = last[num][j];
                    last[num+1][to[j]][i] = 1;
                    
                }
            }
        }
    }
    
    forn(i,0,dmax+1) {
        if(d[i][div.size()-1] != INF) {
            cout<<i<<endl;
            vi ans;
            forn(j,0,1000) if(last[i][div.size()-1][j]) ans.pb(j+1);
            ll curdiv = k;
            int cur = div.size() - 1;
            ll sum = d[i][div.size()-1];
//            while(i>0) {
//                curdiv /= gcd(curdiv, a[last[i][cur]]);
//                ans.pb(last[i][cur] + 1);
//                
//                sum -= a[last[i][cur]];
//                i--;
//                forn(j,0,div.size()-1) {
//                    if(div[j]%curdiv == 0 && d[i][j] == sum) {
//                        cur = j;
//                        curdiv = div[cur];
//                        break;
//                    }
//                }
//            }
            for(auto x:ans) cout<<x<<' ';
            return 0;
        }
    }
    cout<<-1;
    
    
    
}