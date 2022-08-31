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
typedef std::vector<ld> vld;
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
    int k,q;
    cin>>k>>q;
    if(k==1) {
        forn(i,0,q) cout<<1<<endl;
        return 0;
    }
    ld x = ld(k) / ld(k-1);
    int cur = 0;
    vi ans(2000);
    vld p(k+1,0);
    p[0] = 1;
    int st = 0;
    while(1) {
        if(cur > 1000) break;
        while(p[k]*2000 >= cur) ans[cur++] = st;
        vld np(k+1,0);
        np[k] = p[k];
        forn(i,0,k) {
            np[i] += (p[i]*i)/k;
            np[i+1] += (p[i]*(k-i))/k;
        }
        p = std::move(np);
        st++;
    }
    forn(i,0,q) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    
}