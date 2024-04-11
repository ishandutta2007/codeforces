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
    int n,d;
    cin>>n>>d;
    vi a(n);
    forn(i,0,n) cin>>a[i];
    sort(all(a));
    int sum = 0;
    int m = 0;
    forn(i,0,n) {
        if(a[i] > sum + d) {
            break;
        }
        m++;
        sum += a[i];
    }
    vi can(500010, 0);
    can[0] = 1;
    forn(i,0,m) {
        for(int j = 500000; j>=a[i]; j--) {
            if(can[j-a[i]]) can[j] = 1;
        }
    }
    int ans = 0;
    int cur = sum;
    while(cur > 0) {
        ans++;
        cur -= d;
        if(cur<=0) break;
        while(!can[cur]) cur++;
    }
    cout<<sum<<' '<<ans;
    
}