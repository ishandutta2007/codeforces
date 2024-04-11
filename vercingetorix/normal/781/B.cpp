#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

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
    int n;
    cin>>n;
    vector<vs> a(2, vs(n));
    vi var(n,0);
    forn(i,0,n) {
        string s,t;
        cin>>s>>t;
        a[0][i].pb(s[0]); a[0][i].pb(s[1]); a[0][i].pb(s[2]);
        a[1][i].pb(s[0]); a[1][i].pb(s[1]); a[1][i].pb(t[0]);
    }
    map<string, int> cnt;
    forn(i,0,n) cnt[a[0][i]]++;
    forn(it,0,1010) {
        vi to;
        forn(i,0,n) {
            if(var[i] == 0 && cnt[a[0][i]] > 1) {
                to.pb(i);
            }
        }
        for(auto x : to) {
            cnt[a[0][x]]--;
            cnt[a[1][x]]++;
            var[x] = 1;
        }
    }
    for(auto u : cnt) {
        if(u.second > 1) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    forn(i,0,n) cout<<a[var[i]][i] << endl;
}