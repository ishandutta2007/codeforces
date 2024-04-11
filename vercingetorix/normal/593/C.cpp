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

string ati(int i) {
    string s;
    s = "abs((t";
    if(i<0) {
        i=-i;
        s+="+";
    }
    else s+="-";
    s+=to_string(i);
    s+="))";
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    string f="0";
    string g="0";
    int x,y,r;
    forn(i,0,n) {
        cin>>x>>y>>r;
        if(x%2) x++;
        if(y%2) y++;
        f = "(" + f  + "+" +
        "("+to_string(x/2) + "*((" + ati(i-1) + "+" + ati(i+1)+")-("+ati(i)+"+"+ati(i)+")))"
        +")";
        g = "(" + g  + "+" +
        "("+to_string(y/2) + "*((" + ati(i-1) + "+" + ati(i+1)+")-("+ati(i)+"+"+ati(i)+")))"
        +")";
//        g += "+"+to_string(y/2) + "*(" + ati(i-1) + "+" + ati(i+1)+"-"+ati(i)+"-"+ati(i)+")";
    }
    cout<<f<<endl<<g;
    
    
}