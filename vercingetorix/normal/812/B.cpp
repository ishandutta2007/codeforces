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
    vvi a(n,vi(m+2,0));
    vi sum(n,0);
    forn(i,0,n) {
        string s;
        getline(cin, s);
        forn(j,0,m+2) a[i][j] = s[j]-'0';
        forn(j,0,m+2) sum[i] += a[i][j];
    }
    vi d1(n, 10000000);
    vi d2(n, 10000000);
    int pt = 0;
    while(pt<n && sum[pt] == 0) pt++;
    if(pt==n) {
        cout<<0;
        return 0;
    }
    int l = 1;
    int r = m;
    while(a[pt][l] == 0) l++;
    while(a[pt][r] == 0) r--;
    d1[pt] = r;
    d2[pt] = m+1-l;
    forn(i,pt+1,n) {
        if(sum[i] == 0) {
            d1[i] = d1[i-1] + 1;
            d2[i] = d2[i-1] + 1;
        }
        else {
            int l = 1;
            int r = m;
            while(a[i][l] == 0) l++;
            while(a[i][r] == 0) r--;
            d1[i] = 1+min(2*r + d1[i-1], m+1 + d2[i-1]);
            d2[i] = 1+min(2*(m+1-l) + d2[i-1], m+1 + d1[i-1]);
        }
        
    }
    cout<<d1[n-1];
    
}