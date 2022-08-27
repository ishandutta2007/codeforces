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
    int t;
    read(t);
    char c[300010];
    while(t--) {
        int n,k;
        
        scanf("%d %d\n", &n,&k);
        scanf("%s", c);
        string s(c);
        int can = 1;
        forn(r,0,k) {
            vi cnt(3,0);
            for(int i = r; i < n; i+=k) {
                if(s[i] == '0') cnt[0]++;
                else if(s[i]=='1') cnt[1]++;
                else cnt[2]++;
            }
            if(cnt[0]>0 && cnt[1]>0) {
                can = 0;
                break;
            }
            else if(cnt[0] > 0) s[r] = '0';
            else if(cnt[1] >0) s[r] ='1';
        }
        vi cnt(2,0);
        forn(i,0,k) {
            if(s[i]=='0') cnt[0]++;
            else if(s[i]=='1') cnt[1]++;
        }
        if(cnt[0]>k/2) can = 0;
        if(cnt[1]>k/2) can = 0;
        if(can) printf("YES\n");
        else printf("NO\n");
    }
}