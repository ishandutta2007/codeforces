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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    //string s;
    ll ans = 0;
    scanf("%d", &n);
    vpll task;
    vi p(n);
    map<int, ll> minloss, maxloss;
    forn(i,0,n) {
        scanf("%d", &p[i]);
        
    }
    vi t(n);
    ll T=0;
    forn(i,0,n) {
        scanf("%d", &t[i]);
        T+=t[i];
    }
    forn(i,0,n) {
        minloss[p[i]] = T;
        maxloss[p[i]] = 0;
    }
    forn(i,0,n) task.pb(mp((ll)p[i],(ll)t[i]));
    sort(all(task), [](pll a, pll b) -> bool {
        if(a.first*b.second==b.first*a.second) return (a.first<b.first);
        return (a.first*b.second<b.first*a.second);
    });
    reverse(all(task));
    ll curt = 0;
    int cur=0;
    double bestc=1.;
    
    while(cur<n) {
        
        pll curtask = task[cur];
        int curr=cur+1;
        while ((curr<n) && (task[curr].first*curtask.second == task[curr].second*curtask.first)) curr++;
        ll newt=curt;
        forn(i, cur, curr) {
            newt+=task[i].second;
        }
       /* if(curr>cur+1) {
            ll t2=task[curr-1].second;
            ll t1=task[cur].second;
            if(t1!=t2){
                double A = ((double) t1*t1 / (t2-t1) + newt - t2)/(double)T;
                bestc=min(bestc,1./A);
                
            }
        }*/
        forn(i,cur,curr) {
            int pr = task[i].first;
            int dt = task[i].second;
            minloss[pr] = min(minloss[pr], curt+dt);
            maxloss[pr] = max(maxloss[pr], newt);
        }
        cur=curr;
        curt=newt;
    }
    sort(all(p));
    forn(i,0,n-1) {
        ll p1 = p[i];
        ll p2 = p[i+1];
        if(p1==p2) continue;
        ll p1cost = (T-minloss[p[i]])*p[i];
        ll p2cost = (T-maxloss[p[i+1]])*p[i+1];
        ll r = T*(p[i+1]-p[i]);
        ll l = maxloss[p[i+1]]*p[i+1] - p[i]*minloss[p[i]];
        if (l>r) bestc=min(bestc,(double)r/l);
    }
    
    printf("%.10lf", bestc);
   //cout<<ans;
}