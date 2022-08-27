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
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    vi ca(n+1,0), cb(n+1,0);
    forn(i,0,n) {
        ca[i+1]=ca[i];
        if(s[i]=='a') ca[i+1]++;
        
        cb[i+1]=cb[i];
        if(s[i]=='b') cb[i+1]++;
    }
    int l = 1;
    int r = 0;
    int ans = 0;
    int a=0,b=0;
    while(l<=n) {
        while(r<n && (min(ca[r+1]-ca[l-1], cb[r+1]-cb[l-1]) <= k)) r++;
        ans = max(ans, r-l+1);
        l++;
    }
    cout<<ans;
}