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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

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
    int nn,m,w;
    scanf("%d %d", &nn, &w);
    vi aaa(nn);
    vi bbb(w);
    forn(i,0,nn) scanf("%d" , &aaa[i]);
    forn(i,0,w) scanf("%d" , &bbb[i]);
    vi a(nn-1);
    vi b(w-1);
    forn(i,0,nn-1) {
        a[i] = aaa[i+1] - aaa[i];
    }
    forn(i,0,w-1) {
        b[i]=bbb[i+1] - bbb[i];
    }
    if(w>nn) {
        cout<<0;
        return 0;
    }
    if(w==1) {
        cout<<nn;
        return 0;
    }
    vi s;
    forn(i,0,w-1) s.pb(b[i]);
    s.pb(2000000001);
    forn(i,0,nn-1) s.pb(a[i]);
    
    int n = (int) s.size();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    int ans =0;
    for (int i = w; i<n; i++) {
        if(pi[i]==w-1) ans++;
    }
    cout<<ans;
}