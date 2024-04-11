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

ll ask(int t,int i,int j, int k) {
    printf("%d %d %d %d\n", t,i+1,j+1,k+1);
    fflush(stdout);
    ll res;
    scanf("%lld", &res);
    return res;
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    read(n);
    vll s(n);
    vll sg(n);
    forn(i,2,n) {
        s[i] = ask(1,0,1,i);
        sg[i] = ask(2,0,1,i);
    }
    vi ans;
    ans.pb(0);
    for(int x = -1 ; x<=1; x+=2) {
        int ind = -1;
        forn(i,2,n) if(sg[i] == x) if(ind == -1 || s[ind] < s[i]) ind = i;
        vpll p1, p2;
        if(ind != -1) {
            forn(i,2,n) if(sg[i] == x && ind!=i) {
                    if(ask(2, 0, ind, i) == 1) p2.pb(mp(-s[i], i));
                    else p1.pb(mp(s[i], i));
            }
            srt(p1);
            srt(p2);
            for(auto x : p1) ans.pb(x.second);
            ans.pb(ind);
            for(auto x : p2) ans.pb(x.second);
        }
        ans.pb(1);
    }
    ans.pop_back();
    printf("0");
    for(auto x : ans) printf(" %d", x+1);
    printf("\n");
}