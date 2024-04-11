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
    int n;
    cin>>n;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    vi d1(n,0);
    vi d2(n,0);
    vi d0(n,0);
    forn(i,0,n) {
        if(a[i] == 0) {
            if(i>0) {
                d0[i] = min(d1[i-1], d2[i-1]);
                d0[i] = min(d0[i], d0[i-1]);
                d0[i]++;
            }
            else d0[i] = 1;
            d1[i]=31415;
            d2[i]=15155;
        }
        else {
            if(i>0) {
                d0[i] = min(d1[i-1], d2[i-1]);
                d0[i] = min(d0[i], d0[i-1]);
                d0[i]++;
            }
            else d0[i] = 1;
            if(a[i]==1 || a[i]==3) {
                if(i>0) d1[i] = min(d0[i-1], d2[i-1]);
                else d1[i] = 0;
            }
            else d1[i] = 13895;
            if(a[i]==2 || a[i]==3) {
                if(i>0) d2[i] = min(d0[i-1], d1[i-1]);
                else d2[i] = 0;
            }
            else d2[i] = 24897;
        }
    }
    int ans = min(d1[n-1], d2[n-1]);
    ans = min(d0[n-1], ans);
    cout<<ans;
}