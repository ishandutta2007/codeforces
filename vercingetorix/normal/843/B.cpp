#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <random>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
mt19937_64 gen(13875);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,st,x;
    srand(135);
    scanf("%d %d %d", &n, &st, &x);
    vi used(n+1,0);
    used[st] = 1;
    printf("? %d\n", st);
    fflush(stdout);
    int val, nx;
    scanf("%d %d", &val, &nx);
    if(val >= x) {
        printf("! %d\n", val);
        fflush(stdout);
        return 0;
    }
    int best = val;
    int nxind = nx;
    vi left;
    forn(i,1,n+1) if(i!=st) left.pb(i);
    forn(i,0,950) {
        if(left.empty()) break;
        int k = left.size();
        int ind = gen()%k;
        int cur = left[ind];
        swap(left[ind], left[k-1]);
        left.pop_back();
        printf("? %d\n", cur);
        fflush(stdout);
        scanf("%d %d", &val, &nx);
        if(val < x && val > best) {
            best = val;
            ind = cur;
            nxind = nx;
        }
    }
    int cur = best;
    forn(i,0,1000) {
        if(nxind == -1) {
            printf("! -1\n");
            fflush(stdout);
            return 0;
        }
        printf("? %d\n", nxind);
        fflush(stdout);
        scanf("%d %d", &val, &nx);
        if(val >= x) {
            printf("! %d\n", val);
            fflush(stdout);
            return 0;
        }
        nxind = nx;
    }
    
}