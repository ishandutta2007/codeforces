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
    int g,b;
    vi r(3);
    cin>>r[0]>>r[1]>>r[2];
    sort(all(r));
    int k = min(r[1]-r[0], (r[2]-r[1]));
    int ans = 0;
    ans+=k;
    r[1]-=k;
    r[2]-=2*k;
    if(r[0]==r[1]) {
        int l = min(r[0], (r[2]-r[0])/3);
        ans+=2*l;
        r[0]-=l;
        r[1]-=l;
        r[2]-=4*l;
        cout<< ans+r[0];
        return 0;
    }
    if(r[2]>r[1]) {
        ans++;
        r[2]-=2;
        r[1]--;
    }
    int l = (r[2]-r[0])/3;
    r[2]-=3*l;
    r[1]-=3*l;
    ans+=2*l;
    ans+=r[0];
    r[1]-=r[0];
    r[2]-=r[0];
    if(r[1]>1) ans++;
    
    cout<<ans;
}