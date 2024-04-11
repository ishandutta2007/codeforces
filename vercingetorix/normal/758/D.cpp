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
    ll n;
    scanf("%lld\n", &n);
    string s;
    getline(cin , s);
    if(s=="0") {
        cout<<0;
        return 0;
    }

    int pt = s.size() - 1;
    ll dx = 1;
    ll ans = 0;
    while(pt>=0) {
        int ptwas= pt;
        ll cur = 0;
        ll d10 = 1;
        while(pt>=0 && d10*ll(s[pt]-'0')+cur < n) {
            cur = d10*ll(s[pt]-'0')+cur;
            d10 *= 10;
            pt--;
            if(d10>=n) break;
        }
        ans += dx * cur;
        dx *= n;
        if(cur == 0) {
            pt = ptwas - 1;
            continue;
        }
        while(s[pt+1]=='0') pt++;
        
    }
    cout<<ans;
    
    
}