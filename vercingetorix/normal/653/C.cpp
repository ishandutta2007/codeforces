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
    //string s;
    ll ans = 0;
    scanf("%d",&n);
    vi t(n+1);
    t[0]=-1;
    forn(i,1,n+1) scanf("%d", &t[i]);
    vi badind;
    t.pb(-1);
    t.pb(-1);
    forn(i,1,n) {
        if((i&1)&&(t[i]>=t[i+1])) badind.pb(i);
        if(((i%2)==0)&&(t[i]<=t[i+1])) badind.pb(i);
    }
    if(badind.size()>4) {
        cout<<0;
        return 0;
    }
    int uuu = badind.back();
    if(badind.back()<n-1) badind.pb(uuu+1);
    for(int tt=0;tt<2;tt++) {
        int toswap=uuu+tt;
        for(int i =1; i<n+1; i++) {
            if(i==toswap) continue;
            if((tt==1)&&(i==uuu)) continue;
            swap(t[i], t[toswap]);
            bool f = true;
            vi check = badind;
            check.pb(i);
            check.pb(i-1);
            check.pb(toswap);
            check.pb(toswap-1);
            for(auto checking:check) {
                if(checking<1) continue;
                if(checking>=n) continue;
                if((checking&1)&&(t[checking]>=t[checking+1])) f=false;
                if((checking%2==0)&&(t[checking]<=t[checking+1])) f=false;
            }
            if(f) ans++;
            swap(t[i], t[toswap]);
        }
        
    }
    cout<<ans;
}