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
    int n,l,r,ql,qr;
    scanf("%d %d %d %d %d", &n,&l,&r,&ql,&qr);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    
    int rsum = 0;
    int lsum = 0;
    forn(i,0,n) rsum+=a[i];
    int ans = rsum*r+qr*(n-1);
    forn(m,0,n) {
        lsum+=a[m];
        rsum-=a[m];
        int ln = m+1;
        int rn = n-m-1;
        int cand = lsum*l+rsum*r;
        if(rn>ln) cand+=(rn-ln-1)*qr;
        if(rn<ln) cand+=(ln-rn-1)*ql;
        ans=min(ans,cand);
    }
    cout<<ans;
    
}