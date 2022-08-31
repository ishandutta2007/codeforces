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
    string s;
    cin>>s;
    n= s.size();
    if(n<=6) {
        cout<<0;
        return 0;
    }
    vi p2(n+1,0);
    vi p3(n+1,0);
    p2[n] = 1;
    p2[n-2] = 1;
    p3[n] = 1;
    vector<string> ans;
    ans.pb(s.substr(n-2, 2));
    for(int i = n-3; i>=5; i--) {
        if(p3[i+2]) p2[i] = 1;
        if(p2[i+3]) p3[i] = 1;
        if(p2[i+2] && ((i+3)>=n || s[i+2]!=s[i] || s[i+3]!=s[i+1])) p2[i] = 1;
        if(p3[i+3] && ((i+5)>=n || s[i+3]!=s[i] || s[i+4]!=s[i+1] || s[i+5]!=s[i+2])) p3[i] = 1;
        if(p2[i]) ans.pb(s.substr(i,2));
        if(p3[i]) ans.pb(s.substr(i,3));
    }
    sort(all(ans));
    vector<string> rans;
    forn(i,0,ans.size()) {
        if(i==0 || ans[i]!=ans[i-1]) rans.pb(ans[i]);
    }
    cout<<rans.size()<<endl;
    for(auto x: rans) cout<<x<<endl;
}