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
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,n;
    scanf("%d %d", &m, &n);
    vi a(n);
    multiset<int> x;
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    if(n==1) {
        cout<<a[0]<<' '<<0;
        return 0;
    }
    else if(n==m) {
        cout<<"0 1";
        return 0;
    }
    bool invv = false;
    if(2*n > m) {
        vi has(m,0);
        for(auto x : a) has[x] = 1;
        a.clear();
        n= m -n;
        forn(i,0,m) if(!has[i]) a.pb(i);
        invv = true;
        if(n==1) {
            cout<<(a[0]+1)%m<<' '<<1;
            return 0;
        }
    }
    forn(i,0,n) x.insert(a[i]);
    sort(all(a));
    int best = a[0]+m-a[n-1];
    int cnt = 1;
    forn(i,0,n-1) {
        if(a[i+1]-a[i] < best) {
            best = a[i+1] - a[i];
            cnt = 1;
        }
        else if(a[i+1]-a[i] == best) cnt++;
    }
    ll lc = n-cnt;
//    cout<<best<<' '<<cnt<<endl;
//    printf("invmod 1 %d\n", (int)invmod(162, m));
    ll d = ((ll)best*invmod(lc,m))%m;
    int l = a[0];
    int r = a[0];
    x.erase(x.find(a[0]));
    while(1) {
        l = (l+m-d)%m;
        if(x.find(l) == x.end()) {
            l = (l+d)%m;
            break;
        }
        x.erase(x.find(l));
    }
    while(1) {
        r=(r+d)%m;
        if(x.find(r) == x.end()) {
            r = (r+m-d)%m;
            break;
        }
        x.erase(x.find(r));
    }
    if(x.empty()) {
        if(invv) l = (r+d)%m;
        printf("%d %d", l, d);
    }
    else printf("-1");
    
}