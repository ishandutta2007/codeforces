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
    int n,m;
    cin>>n>>m;
    vi can(n,1);
    vi q(m);
    char c;
    vi id(m);
    forn(i,0,m) {
        cin>>c>>id[i];
        id[i]--;
    //    can[id[i]] = 0;
        if(c=='+') q[i] = 1;
        else q[i] = -1;
    }
    
//    if(q[0] == 1) {
        set<int> here;
        forn(i,0,m) {
            if(!here.empty()) {
                if(here.size() > 1) {
                    can[id[i]] = false;
                }
                else if(*(here.begin()) !=id[i]) {
                    can[id[i]] = false;
                }
            }
            if(q[i] == 1) {
                here.insert(id[i]);
                if(i>0 && id[i-1] != id[i]) {
                    can[id[i]] = false;
                }
            }
            else {
                if(here.find(id[i]) != here.end()) {
                    here.erase(id[i]);
                }
            }
        }
//    }
    reverse(all(q));
    forn(i,0,m) q[i] = -q[i];
    reverse(all(id));
    
//    if(q[0] == 1) {
      //  set<int> here;
    here.clear();
        forn(i,0,m) {
            if(!here.empty()) {
                if(here.size() > 1) {
                    can[id[i]] = false;
                }
                else if(*(here.begin()) !=id[i]) {
                    can[id[i]] = false;
                }
            }
            if(q[i] == 1) {
                here.insert(id[i]);
                if(i>0 && id[i-1] != id[i]) {
                    can[id[i]] = false;
                }
            }
            else {
                if(here.find(id[i]) != here.end()) {
                    here.erase(id[i]);
                }
            }
        }
//    }

    
//    if(q[0] == 1) {
//        int test = id[0];
//        bool bosshere = true;
//        bool ca = true;
//        set<int> here;
//        forn(i,1,m) {
//            if(test == id[i]) {
//                if(q[i] == 1) bosshere = true;
//                else {
//                    bosshere = false;
//                    if(!here.empty()) ca = false;
//                }
//                continue;
//            }
//            if(!bosshere) ca = false;
//            if(q[i] == 1) here.insert(id[i]);
//            else {
//                
//                if(here.find(id[i]) == here.end()) {
//                    ca = false;
//                }
//                else {
//                    here.erase(id[i]);
//                }
//            }
//        }
//        if(ca) can[test] = 1;
//    }
    reverse(all(q));
    forn(i,0,m) q[i] = -q[i];
    reverse(all(id));
//    if(q[0] == 1) {
//        int test = id[0];
//        bool bosshere = true;
//        bool ca = true;
//        set<int> here;
//        forn(i,1,m) {
//            if(test == id[i]) {
//                if(q[i] == 1) bosshere = true;
//                else {
//                    bosshere = false;
//                    if(!here.empty()) ca = false;
//                }
//                continue;
//            }
//            if(!bosshere) ca = false;
//            if(q[i] == 1) here.insert(id[i]);
//            else {
//                
//                if(here.find(id[i]) == here.end()) {
//                    ca = false;
//                }
//                else {
//                    here.erase(id[i]);
//                }
//            }
//        }
//        if(ca) can[test] = 1;
//    }
    int ans =0;
    forn(i,0,n) ans+=can[i];
    cout<<ans<<endl;
    forn(i,0,n) if(can[i]) cout<<i+1<<" ";
    
}