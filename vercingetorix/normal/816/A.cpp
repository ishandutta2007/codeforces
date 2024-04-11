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
void inc(int & h, int & m) {
    m++;
    if(m==60) {
        m = 0;
        h++;
        if(h==24) h=0;
    }
}
bool ispal(int h, int m) {
    return (h/10 == m%10) && (h%10 == m/10);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ans = 0;
    string s;
    getline(cin, s);
    int h = int(s[0]-'0')*10 + int(s[1]-'0');
    int m = int(s[3]-'0')*10 + int(s[4]-'0');
    while(!ispal(h,m)) {
        ans++;
        inc(h,m);
    }
    cout<<ans;
    
}