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

long long mod=1000003;

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
    int n;
    cin>>n;
    forn(i,0,n) {
        string s;
        cin>>s;
        string t = s.substr(4, 10);
        ll cur = 1988;
        ll deg10 = 1;
        ll res = 0;
        for(int k = t.size() - 1; k>=0; k--) {
            res += (ll)(t[k]-'0') * deg10;
            deg10 *= 10;
            ll add = (res + deg10 - (cur)%deg10) %deg10;
            if(add==0) add = deg10;
            cur+=add;
        }
        cout<<cur<<endl;
    }
    
    
}