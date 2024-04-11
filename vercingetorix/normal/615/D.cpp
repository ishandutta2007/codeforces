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

ll powM(ll k, ll n, ll modulo) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2,modulo);
    return (((x*x)%modulo)*powM(k, n%2, modulo)) % modulo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,a,b;
    //ll ans=0;
    int m;
    scanf("%d", &m);
    vi p(m);
    forn(i,0,m) scanf("%d", &p[i]);
    sort(all(p));
    int cur = 0;
    vpll r;
    n=m;
    while(cur<n) {
        int curr=cur+1;
        while((curr<n)&&(p[curr]==p[cur])) curr++;
        r.pb(mp(p[cur], curr-cur));
        cur=curr;
    }
    ll degmul = 1;
    for(auto x:r) {
        degmul = (degmul*(x.second+1)) %((ll)2*(mod-1));
    }
    ll ans = 1;
    for(auto x:r) {
        ll degp = ((x.second*degmul)%((ll)2*(mod-1)))/2;
        ans = (ans * powM(x.first, degp, mod)) % mod;
    }
    
    cout<<ans;
}