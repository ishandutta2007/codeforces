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
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    int x,y;
    scanf("%d %d", &x, &y);
    if(abs(x) + abs(y) > n || (abs(x) + abs(y) + n) % 2 != 0) {
        cout<<-1;
        return 0;
    }
    int dx = 0, dy = 0;
    for(auto c : s) {
        if(c=='R') dx++;
        else if(c=='L') dx--;
        else if(c=='U') dy++;
        else if(c=='D') dy--;
    }
    if(dy == y && dx == x) {
        cout<<0;
        return 0;
    }
    char c0 = s[0];
    if(c0=='R') dx--;
    else if(c0=='L') dx++;
    else if(c0=='U') dy--;
    else if(c0=='D') dy++;
    int l = 0;
    int r = 1;
    int k = 1;
    while(abs(dx-x) + abs(dy-y) > k) {
        char c = s[r];
        if(c=='R') dx--;
        else if(c=='L') dx++;
        else if(c=='U') dy--;
        else if(c=='D') dy++;
        r++;
        k++;
    }
    int ans = n;
    ans = min(ans, r-l);
    while(l < n-1) {
        char c = s[l];
        if(c=='R') dx++;
        else if(c=='L') dx--;
        else if(c=='U') dy++;
        else if(c=='D') dy--;
        l++; k--;
        if(r == l) {
            char c0 = s[l];
            if(c0=='R') dx--;
            else if(c0=='L') dx++;
            else if(c0=='U') dy--;
            else if(c0=='D') dy++;
            r++; k++;
        }
        while(r < n && abs(dx-x) + abs(dy-y) > k) {
            char c = s[r];
            if(c=='R') dx--;
            else if(c=='L') dx++;
            else if(c=='U') dy--;
            else if(c=='D') dy++;
            r++; k++;
        }
        if(abs(dx-x) + abs(dy-y) <= k) ans = min(ans, r-l);
    }
    cout<<ans;
    
}