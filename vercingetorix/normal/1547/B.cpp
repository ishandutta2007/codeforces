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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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
    int t;
    scanf("%d\n", &t);
    while(t--) {
        char c[30];
        scanf("%s", c);
        string s(c);
        int n = s.size();
        vi pos(n, -1);
        int can = 1;
        forn(i,0,n) {
            if(s[i] - 'a' >=n) {
                can = 0;
                break;
            }
            pos[s[i]-'a'] = i;
        }
        int l = n+1;
        int r = -1;
        forn(i,0,n) {
            if(pos[i] == -1) {
                can = 0;
                break;
            }
            if(i>0) {
                if(pos[i] > r+1 || pos[i] < l-1) {
                    can=0;
                    break;
                }
            }
            r = max(r,pos[i]);
            l = min(l,pos[i]);
        }
        if(can) printf("YES\n");
        else printf("NO\n");
        
    }
}