#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair


int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int ans = 0;
    ll w,h,n;
    cin >> w >> h >> n;
    set<ll> hcut, vcut;
    set<ll> hparts, vparts;
    hcut.insert(0);
    hcut.insert(h);
    hparts.insert(h);
    vparts.insert(w);
    vcut.insert(0);
    vcut.insert(w);
    map<ll, ll> vp, hp;
    vp[w] = 1;
    hp[h] = 1;
    char c;
    int  x;
    for (int i=0; i<n; i++) {
        cin >> c >> x;
        if (c=='V') {
            auto it = vcut.insert(x).first;
            auto it2=it;
            auto it3=it;
            int l = *(--it2);
            int r = *(++it3);
            vp[r-l]--;
            if(vp[r-l] == 0) {
                vparts.erase(r-l);
            }
            vp[r-x]++;
            if(vp[r-x] == 1) {
                vparts.insert(r-x);
            }
            vp[x-l]++;
            if(vp[x-l] == 1) {
                vparts.insert(x-l);
            }
        }
        else {
            auto it = hcut.insert(x).first;
            auto it2=it;
            auto it3=it;
            int l = *(--it2);
            int r = *(++it3);
            hp[r-l]--;
            if(hp[r-l] == 0) {
                hparts.erase(r-l);
            }
            hp[r-x]++;
            if(hp[r-x] == 1) {
                hparts.insert(r-x);
            }
            hp[x-l]++;
            if(hp[x-l] == 1) {
                hparts.insert(x-l);
            }
        }
        auto itv = vparts.end(); itv--;
        auto ith = hparts.end(); ith--;
        cout << *(itv) * *(ith) << endl;
    }


}