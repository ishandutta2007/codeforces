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
int a,b;
vi cur;
vi ans;

void go(int b) {
    if(b<a) return;
    if(b==a) ans = cur;
    if(b%2 == 0) {
        int b2 = b/2;
        cur.pb(b2);
        go(b2);
        cur.pop_back();
    }
    if(b%10 == 1) {
        int b2 = b/10;
        cur.pb(b2);
        go(b2);
        cur.pop_back();
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    
    cin>>a>>b;
    cur.pb(b);
    go(b);
    if(ans.empty()) cout<<"NO";
    else {
        reverse(all(ans));
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(auto x:ans) cout<<x<<' ';
    }
}