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
    int n,k;
    cin>>n;
    //for(int i=0; i<n; i++) 
    vi l(n);
    vi d(n);
    vvi fixl(100001);
    vvi fixli(100001);
    int ans=300000000;
    int cur=0;
    int curn=n;
    int allz=0;
    fo(i,0,n) cin>>l[i];
    set<pi> zat;
    fo(i,0,n) {
        cin>>d[i];
        allz+=d[i];
        fixl[l[i]].pb(d[i]);
        fixli[l[i]].pb(i);
        zat.insert(mp(d[i],i));
    }
    zat.insert(mp(0,0));
    for(int i=100000; i>=1; i--) {
        if(fixl[i].size()==0) continue;
        fo(j,0,fixl[i].size()) {
            zat.erase(mp(fixl[i][j], fixli[i][j]));
            //cur+=fixl[i][j];
            allz-=fixl[i][j];
        }
        curn-=fixl[i].size();
        int newz=allz;
        int curost=0;
        auto it=zat.end();
        it--;
        while(curost<min((int)(fixl[i].size())-1, curn)) {
            newz-=it->first;
            curost++;
            it--;
        }
        if(newz+cur<ans) ans=newz+cur;
        
        fo(j,0,fixl[i].size()) {
            //zat.erase(mp(fixl[i][j], fixli[i][j]));
            cur+=fixl[i][j];
           //allz-=fixl[i][j];
        }
    }
    cout<<ans;
    
}