#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
int pow2(int k, int n) {
    if (n==0) return 1;
    if(n==1) return k;
    int x = pow2(k, n/2);
    return x*x*pow2(k, n%2);
}
long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    std::vector<bool> isp(1001,false);
    
    std::vector<int> p;
    for(int i=2; i<=1000; i++){
        bool f=false;
        for(int j=0; j<p.size();j++) if(i%p[j]==0){
            f=true;
            break;
        }
        if(f) continue;
        p.push_back(i);
        isp[i]=true;
    }
    
    int n,m,k;
   // string s;
    ll ans = 0;
    scanf("%d",&n);
    if(n==1) {
        cout<<0;
        return 0;
    }
    vi a(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    vi razl;
    int curn = n;
    for(auto pr:p) {
        while(curn%pr==0) {
            razl.pb(pr);
            curn/=pr;
        }
    }
    if(curn>1) razl.pb(curn);
    vi un;
    un.pb(razl[0]);
    map<int,int> deg;
    for(auto pr:razl) deg[pr]++;
    forn(i,1,razl.size()) {
        if(razl[i]!=razl[i-1]) un.pb(razl[i]);
    }
    while(un.size() <6) un.pb(1);
    vi degs;
    vi ansford(n, 0);
    vvi skokad(n+1);
    forn(i,0,6) degs.pb(deg[un[i]]);
    forn(i0,0,degs[0]+1)
    forn(i1,0,degs[1]+1)
    forn(i2,0,degs[2]+1)
    forn(i3,0,degs[3]+1)
    forn(i4,0,degs[4]+1)
    forn(i5,0,degs[5]+1) {
        int d = pow2(un[0],i0) *pow2(un[1],i1) *pow2(un[2],i2) *pow2(un[3],i3) *pow2(un[4],i4) *pow2(un[5],i5);
        if(d==n) continue;
        vi maxcat(d, 0);
        forn(i,0,n) maxcat[i%d] = max(maxcat[i%d], a[i]);
        //cout<<d<<endl;
        //int ansford = 0;
        int curbest = 0;
        int curcat = 0;
        vi skoka(n+1,0);
        forn(i, 0, n) {
            if(a[i] == maxcat[curcat]) curbest++;
            else curbest = 0;
            //if(curbest>=d) ansford[d]++;
            //skoka[curbest]++;
            curcat++;
            if(curcat==d) curcat = 0;
        }
        forn(i, 0, n) {
            if(a[i] == maxcat[curcat]) curbest++;
            else curbest = 0;
            if(curbest>n) curbest = n;
            //if(curbest>=d) ansford[d]++;
            skoka[curbest]++;
            curcat++;
            if(curcat==d) curcat = 0;
        }
        skokad[d].resize(n+1);
        skokad[d][n]=skoka[n];
        for(int j= n-1; j>=0; j--) {
            skokad[d][j] = skokad[d][j+1] + skoka[j];
        }
    }
    
    forn(s,1,n){
        //cout<<s<<" "<<gcd(s,n)<<" "<<skokad[gcd(s,n)][s]<<endl;
        ans+=skokad[gcd(s,n)][s];//ans+=ansford[gcd(s,n)];
    }
    //cout<<0;
    cout<<ans;
}