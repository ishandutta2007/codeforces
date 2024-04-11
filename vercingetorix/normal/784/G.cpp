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
    string s;
    cin>>s;
    s = "+"+s;
    int p = (int)s.size()-1;
    int ans = 0;
    while(p>0) {
        int cur = 0;
        int d10 = 1;
        while(s[p] >= '0' && s[p] <= '9') {
            cur += d10*int(s[p]-'0');
            d10*=10;
            p--;
        }
        if(s[p]=='-') cur*=-1;
        p--;
        ans+=cur;
    }
    vi res;
    if(ans==0) res.pb(0);
    while(ans>0) {
        res.pb(ans%10);
        ans/=10;
    }
    reverse(all(res));
    cout<<string(res[0], '+') << "++++++++++++++++++++++++++++++++++++++++++++++++.\n";
    forn(i,1,res.size()) {
        int df = res[i]-res[i-1];
        if(df>0) cout<<string(df,'+')<<".\n";
        else cout<<string(-df,'-')<<".\n";
    }
    
    
}