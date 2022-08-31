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
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs s(n);
    forn(i,0,n) getline(cin, s[i]);
    int cnt = 0;
    int mnx = 101;
    int mxx = -1;
    int mny = 101;
    int mxy = -1;
    forn(i,0,n) forn(j,0,m) {
        if(s[i][j] == 'B') {
            cnt++;
            mxx=max(mxx,i);
            mxy=max(mxy,j);
            mnx=min(mnx,i);
            mny=min(mny,j);
        }
    }
    if(cnt==0) cout<<1;
    else {
        int l = 1+max(mxx-mnx, mxy-mny);
        if(l>min(m,n)) cout<<-1;
        else cout<<l*l-cnt;
    }
}