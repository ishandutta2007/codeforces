#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k,h,q;
    cin>>h>>q;
    //for(int i=0; i<n; i++) 
    vector<pair<pi,int>> zap;
    ll truelev=0;
    vi inct, dect, incf, decf;
    ll p2=1;
    fo(i,0,h) p2*=2;
    multiset<pair<ll, ll>> events;
    events.insert(mp(p2,0));
    events.insert(mp(p2/2,0));
    for(int i=0; i<q; i++) {
        ll l,r;
        int lev, an;
        cin>>lev>>l>>r>>an;
        while (lev<h) {
            lev++;
            l=2*l;
            r=2*r+1;
        }
        zap.pb(mp(mp(l,r), an));
        if(an==1) {
            truelev++;
            inct.pb(l);
            dect.pb(r+1);
            events.insert(mp(l,1));
            events.insert(mp(r+1,2));
        }
        else {
            incf.pb(l);
            decf.pb(r+1);
            events.insert(mp(l,3));
            events.insert(mp(r+1,4));
        }
    }
    ll tl=0, fl=0;
    vll posans;
    ll pos=events.begin()->first;
    for(auto it=events.begin(); it!=events.end(); it++) {
        if ((it->first)!=pos) {
            if((tl==truelev)&&(fl==0)) {
                posans.pb(pos);
                if(it->first>pos+1) posans.pb(pos+1);
            }
        }
        if(it->second==1) tl++;
        if(it->second==2) tl--;
        if(it->second==3) fl++;
        if(it->second==4) fl--;
        pos=it->first;
    }
    if(posans.size()>1) {
        cout<<"Data not sufficient!";
    }
    else if(posans.size()<1) {
        cout<<"Game cheated!";
    }
    else {
        cout<<posans[0];
    }
}