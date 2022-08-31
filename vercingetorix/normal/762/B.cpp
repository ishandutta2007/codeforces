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
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    int was = a+b+c;
    int m;
    scanf("%d", &m);
    vpi ms;
    forn(i,0,m) {
        char c[10];
        int x;
        scanf("%d %s", &x, c);
        string s(c);
        int t = 1;
        if(s=="USB") t=  0;
        ms.pb(mp(x,t));
    }
    sort(all(ms));
    ll ans = 0;
    forn(i,0,m) {
        if(ms[i].second == 0) {
            ans+=ms[i].first;
            if(a>0) a--;
            else if(c>0) c--;
            else ans-=ms[i].first;
        }
        else {
            ans+=ms[i].first;
            if(b>0) b--;
            else if(c>0) c--;
            else ans-=ms[i].first;
        }
    }
    cout<<was-a-b-c<<' '<<ans;
    
//    for(auto x : ms) cout<<x.first<<' '<<x.second<<endl;
    
    
}