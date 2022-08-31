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
    read(t);
    char c[1004];
    while(t--) {
        int n,r;
        scanf("%d\n", &n);
        scanf("%s", c);
        string s(c);
        vi can(26,0);
        forn(i,0,n) can[s[i]-'a'] = 1;
        int did = 0;
        forn(i,0,26) {
            if(can[i] == 0) {
                did = 1;
                printf("%c\n", 'a' + i);
                break;
            }
        }
        if(did) continue;
        can = vi(26*26,0);
        forn(i,0,n-1) {
            can[int(s[i]-'a')*26 + s[i+1]-'a'] = 1;
        }
        forn(i,0,26*26) {
            if(can[i] == 0) {
                printf("%c%c\n", 'a'+i/26, 'a'+i%26);
                did = 1;
                break;
            }
        }
        if(did) continue;
        can = vi(2*26*26,0);
        forn(i,0,n-2) {
            if(s[i] == 'a' || s[i] == 'b')
            can[int(s[i]-'a')*26*26 + int(s[1+i]-'a')*26 + s[i+2]-'a'] = 1;
        }
        forn(i,0,2*26*26) {
            if(can[i] == 0) {
                printf("%c%c%c\n", 'a'+i/(26*26),'a'+(i/26)%26, 'a'+i%26);
                did = 1;
                break;
            }
        }
    }
    
}