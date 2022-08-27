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
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<unsigned int> vi;
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

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

vi deg2;
vi ch;
ll ans  = 0;
int n;
void go2(int l1, int r1, int l2, int r2, unsigned int k, unsigned int curdeg) {
    if(k==0) { ans += ((ll)(r1-l1)* (ll)(r2-l2)); return;}
    if(l1==r1 || l2==r2) return;
    int x1 = lower_bound(ch.begin()+l1, ch.begin()+r1, curdeg) - ch.begin();
    int x2 = lower_bound(ch.begin()+l2, ch.begin()+r2, curdeg) - ch.begin();
    if (curdeg >= k) {
        ans += (ll)(x1-l1) * (ll)(r2-x2);
        ans += (ll)(x2-l2) * (ll)(r1-x1);
        forn(u,x1,r1) ch[u]^=curdeg;
        forn(u,x2,r2) ch[u]^=curdeg;
        if(x1>l1 && x2>l2) go2(l1,x1,l2,x2,k,curdeg/2);
        if(r1>x1 && r2>x2) go2(x1,r1,x2,r2,k,curdeg/2);
        return;
    }
    else {
        forn(u,x1,r1) ch[u]^=curdeg;
        forn(u,x2,r2) ch[u]^=curdeg;
        if(x1>l1 && r2>x2) go2(l1,x1,x2,r2,k^curdeg,curdeg/2);
        if(x2>l2 && r1>x1) go2(l2,x2,x1,r1,k^curdeg,curdeg/2);
    }
    
}

void go(int l, int r, unsigned int k, unsigned int curdeg) {
    if(k==0) { ans += ((ll)(r-l)* (ll)(r-l-1))/2; return;}
    if (l==r) return;
    int x = lower_bound(ch.begin()+l, ch.begin()+r, curdeg) - ch.begin();
    if (curdeg >= k) {
        ans += (ll)(x-l) * (ll)(r-x);
        if(x>l) go(l,x,k,curdeg/2);
        forn(u,x,r) ch[u]^=curdeg;
        if(r>x) go(x,r,k,curdeg/2);
        return;
    }
    else {
        forn(u,x,r) ch[u]^=curdeg;
        if(x>l && r>x) go2(l,x,x,r,k^curdeg,curdeg/2);
    }
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    unsigned int d2 = 1;
    forn(i,0,32) {
        deg2.pb(d2);
        d2*=2;
    }
    unsigned int k;
    scanf("%d %d",&n,&k);

    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    int sum = 0;
    ch.pb(0);
    forn(i,0,n) {
        sum = sum^a[i];
        ch.pb(sum);
    }
    sort(all(ch));
    go(0,n+1,k,deg2[31]);
    cout<<ans;
    
}