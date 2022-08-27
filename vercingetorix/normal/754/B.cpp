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
    vs s(4);
    forn(i,0,4) getline(cin, s[i]);
    vvi a(4,vi(4,0));
    forn(i,0,4) forn(j,0,4) {
        if(s[i][j] == 'x') a[i][j] = 10;
        else if(s[i][j] == '.') a[i][j] = 0;
        else if(s[i][j] == 'o') a[i][j] = 1;
    }
    forn(i,0,4) {
        forn(j,0,4) {
            forn(si,-1,2) {
                forn(sj,-1,2) {
                    if(si==0 && sj ==0) continue;
                    int i2 = i+2*si;
                    int j2 = j+2*sj;
                    if(i2<0 || i2>3 || j2<0 || j2>3) continue;
                    int cnt = a[i][j] + a[i2][j2] + a[i+si][j+sj];
                    if(cnt == 20) {
                        cout<<"YES";
                        return  0;
                    }
                }
            }
        }
    }
    cout<<"NO";
    
}