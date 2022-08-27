#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <stack>
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
const ll INF = mod*mod*4;

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
    int n,m,d;
    scanf("%d %d %d", &n, &m,&d);
    vi a, b, t;
    a.resize(m);
    b.resize(m);
    t.resize(m);
    t.pb(mod);
    forn(i,0,m) {
         scanf("%d %d %d", &a[i], &b[i], &t[i]);
         a[i]--;
    }
    vi A(n,0);
    for(int i = m-1; i>=0; i--) {
        vi B(n,0);
        ll dist2 = (ll) (t[i+1]-t[i]) * (ll) d;
        dist2 = min(dist2, (ll)n-1);
        int dist = dist2;
        int l = - dist-1;
        int r = dist-1;
        deque<pi> q;
        forn(i,0,r+1) {
            while(!q.empty() && q.front().first <= A[i]) q.pop_front();
            q.push_front(mp(A[i],i));
        }
        forn(pos, 0, n) {
            r++;
            if(r<n) {
                while(!q.empty() && q.front().first <= A[r]) q.pop_front();
                q.push_front(mp(A[r],r));
            }
            l++;
            while(q.back().second < l) q.pop_back();
            B[pos] = q.back().first - (abs)(pos - a[i]);
        }
        A= std::move(B);
        B.clear();
    }
    ll ans = - INF;
    forn(i,0,n) ans = max(ans,(ll) A[i]);
    forn(i,0,m) ans += (ll)b[i] ;
    cout<<ans;
}