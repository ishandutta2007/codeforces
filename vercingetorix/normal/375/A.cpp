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
    cin>>s;
    n = s.size();
    forn(i,0,n) if(s[i] == '1') swap(s[i], s[n-4]);
    forn(i,0,n) if(s[i] == '6') swap(s[i], s[n-3]);
    forn(i,0,n) if(s[i] == '8') swap(s[i], s[n-2]);
    forn(i,0,n) if(s[i] == '9') swap(s[i], s[n-1]);
    int ost = 0;
    forn(i,0,n-4) {
        ost = (ost*10 + (int)(s[i]-'0'))%7;
    }
    s.resize(n-4);
    ost = (ost * 10000)%7;

    if(ost==0) s= s+"1869";
    if(ost==1) s= s+"1896";
    if(ost==2) s= s+"1986";
    if(ost==3) s= s+"1698";
    if(ost==4) s= s+"6891";
    if(ost==5) s= s+"1689";
    if(ost==6) s= s+"1968";
    int cur= 0;
    while(s[cur]=='0') cur++;
    string t = s.substr(cur,n) + s.substr(0,cur);
    cout<<t;
}