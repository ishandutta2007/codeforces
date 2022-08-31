#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

typedef std::vector<std::pair<int, pi> > vpip;
long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
int n,m,s;
vi a,b,c;
vpip  powGreed;
vi best;
bool test(int days) {
    int curtask = m-1;
    int curst = n-1;
    ll z = 0;
    set<pi> greeds;
    deque<int> cand;
    while(curtask >= 0) {
        while ((curst>=0) && (powGreed[curst].first >= a[curtask])) {
            greeds.insert(powGreed[curst].second);
            curst--;
        }
        if(greeds.size() == 0) return false;
        auto a = greeds.begin();
        z+=(*a).first;
        forn(i, 0, min(days, curtask+1)) cand.push_front(a->second);
        curtask-=days;
        greeds.erase(a);
    }
    if(z>s) return false;
    else {
        best.clear();
        for(auto x:cand) best.pb(x);
        return true;
        
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    


    scanf("%d %d %d", &n,&m,&s);
        vi ans(m);
    a.resize(m);
    vpi reord;
    b.resize(n);
    c.resize(n);
    forn(i,0,m) {
        scanf("%d", &a[i]);
        reord.pb(mp(a[i], i));
    }
    forn(i,0,n) scanf("%d", &b[i]);
    forn(i,0,n) {
        scanf("%d", &c[i]);
        powGreed.pb(mp(b[i], mp(c[i], i+1)));
    }
    sort(all(a));
    sort(all(reord));
    sort(all(powGreed));
    bool f= false;
    forn(i, 0, n) {
        if ((b[i]>=a.back()) && (c[i] <=s)) f=true;
    }
    if(!f) {
        printf("NO");
        return 0 ;
    }
    int l = 0;
    int r = m;
    test(m);
    while(r-l>1) {
        int med = (r+l)/2;
        if(test(med)) r= med;
        else l=med;
    }
    printf("YES\n");
    forn(i,0,m) {
        ans[reord[i].second] = best[i];
    }
    for(auto x : ans) printf("%d ", x);
    //cout<<ans;
}