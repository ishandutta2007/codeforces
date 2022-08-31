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
    string s,t;
    getline(cin, s);
    getline(cin, t);
    sort(all(s));
    sort(all(t));
    reverse(all(t));
    int n = s.size();
    int mv = 0;
    int il = n/2;
    int ol = n-il;
    int pti = 0;
    int pto = 0;
    string ans(n, ' ');
    forn(i,0,n) {
        if(mv == 0) {
            if(s[pto] < t[pti]) {
                ans[i] = (s[pto++]);
            }
            else break;
            ol--;
        }
        else {
            if(s[pto] < t[pti]) {
                ans[i] = (t[pti++]);
            }
            else break;
            il--;
        }
        mv = 1-mv;
    }
    int cur = n-1;
    while(ol+il > 0) {
        if(mv == 0) ans[cur--] = s[pto - 1 + ol--];
        else ans[cur--] = t[pti - 1 + il--];
        mv = 1-mv;
    }
    printf("%s", ans.c_str());
}