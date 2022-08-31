#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,h,w;
    scanf("%d %d %d\n", &n,&h,&w);
    string s;
    getline(cin, s);
    ll ans = 0;
    int l=0, r=0, u=0,d=0;
    int x=0;
    int y=0;
    vi lu,ru,du,uu;
    forn(i,0,n) {
        if(d-u>=h) break;
        if(r-l>=w) break;
        int nx = x;
        int ny = y;
        char c=s[i];
        if(c=='L') nx--;
        if(c=='R') nx++;
        if(c=='U') ny--;
        if(c=='D') ny++;
        if(nx<l) {
            lu.pb(i);
            l=nx;
            ans+=(ll)(i+1) * (h-(d-u));
        }
        if(nx>r) {
            ru.pb(i);
            r=nx;
            ans+=(ll)(i+1) * (h-(d-u));
        }
        if(ny>d){
            du.pb(i);
            d=ny;
            ans+=(ll)(i+1) * (w-(r-l));
        }
        if(ny<u){
            uu.pb(i);
            u=ny;
            ans+=(ll)(i+1) * (w-(r-l));
        }
        x=nx; y=ny;
    }
    if(d-u<h && r-l<w && x==0 && y==0) {
        cout<<-1;
        return 0;
    }
    ll pref = n;
    vi ev;
    reverse(all(lu));
    reverse(all(du));
    reverse(all(ru));
    reverse(all(uu));
    if(x<0) {
        forn(i,0,-x) ev.pb(lu[i]);
    }
    if(x>0) {
        forn(i,0,x) ev.pb(ru[i]);
    }
    if(y<0) {
        forn(i,0,-y) ev.pb(uu[i]);
    }
    if(y>0) {
        forn(i,0,y) ev.pb(du[i]);
    }
    sort(all(ev));
    int pt = 0;
    while(d-u<h && r-l<w) {
        ll i = ev[pt];
        char c=s[i];
        i += pref;
        i=i%mod;
        if(c=='L') {
            l--;
            ans+=(ll)(i+1) * (h-(d-u));
        }
        if(c=='R') {
            r++;
            ans+=(ll)(i+1) * (h-(d-u));
        }
        if(c=='U') {
            u--;
            ans+=(ll)(i+1) * (w-(r-l));
        }
        if(c=='D') {
            d++;
            ans+=(ll)(i+1) * (w-(r-l));
        }
        ans = ans % mod;
        pt++;
        if(pt==ev.size()) {
            pref+=n;
            pt=0;
        }
    }
    cout<<ans % mod;
    
    
}