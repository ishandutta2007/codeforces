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
    int n,m,p;
    scanf("%d %d %d\n", &n, &m, &p);
    string(s);
    getline(cin, s);
    vi par(n+1);
    vi nr(n+2);
    vi nl(n+2);
    forn(i,0,n+2) {
        nr[i]=i+1;
        nl[i]=i-1;
    }
    int cur = p;
    vi op;
    op.reserve(250000);
    forn(i,1,n+1) {
        if(s[i-1]=='(') op.pb(i);
        else {
            par[i] = op.back();
            par[op.back()] = i;
            op.pop_back();
        }
    }
    string t;
    getline(cin, t);
    forn(i,0,m) {
        if(t[i]=='L') cur = nl[cur];
        else if(t[i]=='R') cur = nr[cur];
        else {
            int a = par[cur];
            int b = cur;
            if(a>b) swap(a,b);
            cur = nr[b];
            if(cur==n+1) cur = nl[a];
            int pa = nl[a];
            int pb = nr[b];
            nr[pa] = pb;
            nl[pb] = pa;
        }
    }
    string ans;
    cur = nr[0];
    while(cur != n+1) {
        ans.pb(s[cur-1]);
        cur=nr[cur];
    }
    printf("%s", ans.c_str());
}