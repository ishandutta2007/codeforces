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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int num[700001];
map<int, int> has[10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    char c[10];
    scanf("%d\n", &n);
    vi d10(1,1);
    forn(i,0,9) d10.pb(d10.back()*10);
    forn(i,0,n) {
        scanf("%s", c);
        int cur = 0;
        forn(j,0,9) cur += d10[j] * int(c[j] - '0');
        num[i] = cur;
        forn(j,0,9) {
            forn(k,j,9) {
                int pc = cur % d10[k-j+1];
                has[k-j+1][pc]++;
            }
            cur /= 10;
        }
    }
    forn(i,0,n) {
        int cur = num[i];
        int best = 9;
        int ans = cur;
        bool done = false;
        forn(len, 1, 10) {
            vi d;
            forn(j,0,10-len) {
                int pc = (cur/d10[j]) % d10[len];
                d.pb(pc);
            }
            sort(all(d));
            int pt = 0;
            while(pt < d.size()) {
                int pr = pt+1;
                while(pr < d.size() && d[pr] == d[pt]) pr++;
                if(has[len][d[pt]] == pr-pt) {
                    forn(j,0,len){
                        printf("%d", d[pt]%10);
                        d[pt]/=10;
                    }
                    printf("\n");
                    done = true;
                    break;
                }
                pt = pr;
            }
            if (done) break;
        }
    }
    
}