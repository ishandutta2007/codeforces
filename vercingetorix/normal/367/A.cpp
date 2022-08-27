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
    getline(cin,s);
    vi x,y,z;
    int n = s.size();
    int cx=0,cy=0,cz=0;
    forn(i,0,n) {
        if(s[i] == 'x') cx++;
        if(s[i] == 'y') cy++;
        if(s[i] == 'z') cz++;
        x.pb(cx);
        y.pb(cy);
        z.pb(cz);
    }
    int m;
    scanf("%d", &m);
    forn(i,0,m) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--; r--;
        int a = x[r]; if(l>0) a-=x[l-1];
        int b = y[r]; if(l>0) b-=y[l-1];
        int c = z[r]; if(l>0) c-=z[l-1];
        vi lol = {a,b,c};
        sort(all(lol));
        if(lol.back() - lol[0] <= 1 || (a+b+c)<3) printf("YES\n");
        else printf("NO\n");
    }
    
    
    
}