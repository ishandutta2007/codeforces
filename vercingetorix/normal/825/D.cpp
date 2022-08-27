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
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s,t;
    getline(cin, s);
    getline(cin, t);
    vll tcnt(26,0);
    vll scnt(26,0);
    int fr = 0;
    string frto;
    for(auto x : t) tcnt[x-'a']++;
    for(auto x : s) {
        if(x=='?') fr++;
        else scnt[x-'a']++;
    }
    forn(k,1,1000001) {
        forn(i,0,26) {
            while(fr>0 && scnt[i] < k*tcnt[i]) {
                scnt[i]++;
                fr--;
                frto.pb('a'+i);
            }
        }
    }
    int pt = 0;
    forn(i,0,s.size()) if(s[i]=='?') s[i] = frto[pt++];
    printf("%s", s.c_str());
    
    
}