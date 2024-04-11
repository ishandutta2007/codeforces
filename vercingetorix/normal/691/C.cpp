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
    int n;
    string s;
    getline(cin,s);
    int pt = 0;
    while (pt < s.size() && (s[pt] == '0' || s[pt] == '.')) {
//        cout << s[pt]<<endl;
        pt++;
    }
    int u = s.find('.');
    if(u==-1) u= s.size();
    //s = s.substr(pt);
    string ans;
    ans.pb(s[pt]);
    ans.pb('.');
    forn(i,pt+1, s.size()) {
        if(s[i]!='.') ans.pb(s[i]);
    }
    pt++;
    int shift;
    if(pt==u) shift = 0;
    else {
        if(u>pt) shift = u-pt;
        else {
            shift = u-pt+1;
        }
    }
    while(ans.back() == '0' || ans.back() == '.') ans.pop_back();
    if(shift!=0) ans+="E"+to_string(shift);
    printf("%s", ans.c_str());
}