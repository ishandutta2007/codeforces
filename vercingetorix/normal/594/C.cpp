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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    string s;
    ll ans = 0;
    //cin >> n >> k;
    scanf("%d %d", &n, &k);
    vpi l, r, t,b;
    forn(i,0,n) {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        l.pb(mp(x1+x2,i));
        b.pb(mp(y1+y2,i));
        r.pb(mp(x1+x2,i));
        t.pb(mp(y2+y1,i));
    }
    sort(all(l));
    sort(all(b));
    sort(all(t));
    sort(all(r));
    reverse(all(r));
    reverse(all(t));
    ll bestS = 1999999999999999999;
    vb del(n, false);
    for(int dl=0; dl<=k; dl++) {
        for(int dr=0; dr<=k-dl; dr++) {
            for(int dt=0; dt<=k-dl-dr; dt++) {
                int db=k-dl-dr-dt;
                vi cdel;
                forn(i,0,dl) {
                    int v=l[i].second;
                    cdel.pb(v);
                    del[v]=true;
                }
                auto pt = t.begin();
                forn(i,0,dt) {
                    while(del[pt->second]) pt++;
                    cdel.pb(pt->second);
                    del[pt->second]=true;
                }
                pt = r.begin();
                forn(i,0,dr) {
                    while(del[pt->second]) pt++;
                    cdel.pb(pt->second);
                    del[pt->second]=true;
                }
                pt = b.begin();
                forn(i,0,db) {
                    while(del[pt->second]) pt++;
                    cdel.pb(pt->second);
                    del[pt->second]=true;
                }
                pt = t.begin()+dt;
                auto pb=b.begin()+db;
                auto pr=r.begin()+dr;
                auto pl=l.begin()+dl;
                while(del[pt->second]) pt++;
                while(del[pb->second]) pb++;
                while(del[pr->second]) pr++;
                while(del[pl->second]) pl++;
                ll w = (pr->first - pl->first + 1) /2;
                ll h = (pt->first - pb->first + 1) /2;
                if(w==0) w=1;
                if(h==0) h=1;
                bestS = min(bestS, w*h);
                for(auto xxx:cdel) del[xxx] = false;
            }
        }
    }
    cout<<bestS;    //cout<<ans;
}