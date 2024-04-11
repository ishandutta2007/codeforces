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
    getline(cin, s);
    int l = 0;
    ll ans = 0;
    while(l<s.size()) {
        while(s[l] >= 'a' && s[l]<='z') l++;
        int r = l+1;
        while(r<s.size() && (s[r] < 'a' || s[r]>'z')) r++;
        string t= s.substr(l,r-l);
        string pr;
        for(auto x : t) if(x!='.') pr.pb(x);
        if(t.size() <= 2 || t[t.size() -3] !='.') pr= pr+"00";
        
        ans += stoll(pr);
        l=r;
    }
    string pr = to_string(ans);
    reverse(all(pr));
    while(pr.size()<3) pr.pb('0');
    string res;
    forn(i,0,pr.size()) {
        if((i-2)%3 == 0) res.pb('.');
        res.pb(pr[i]);
    }
    reverse(all(res));
    if(res[res.size()-1]=='0' && res[res.size()-2]=='0') {
        res.pop_back();
        res.pop_back();
        res.pop_back();
    }
    cout<<res;
    
    
}