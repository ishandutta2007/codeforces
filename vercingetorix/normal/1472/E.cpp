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
    forn(afaff,0,t) {
        int n;
        read(n);
        vector<pair<pi, int>> a(n);
        forn(i,0,n) scanf("%d %d", &a[i].first.first, &a[i].first.second);
        forn(i,0,n) a[i].second = i;
        forn(i,0,n) if(a[i].first.second<a[i].first.first) swap(a[i].first.first, a[i].first.second);
        sort(all(a));
        int best = -1;
        vi ans(n, -1);
        int pt = 0;
        while(pt < n) {
            int j = pt+1;
            while(j<n and a[pt].first.first == a[j].first.first) j++;
            int nb = best;
            forn(i,pt,j) {
                if(best >= 0 and a[best].first.second < a[i].first.second) ans[a[i].second] = a[best].second+1;
                if(nb == -1 or a[nb].first.second > a[i].first.second) nb = i;
            }
            best = nb;
            pt = j;
        }
        forn(i,0,n){
            printf("%d", ans[i]); if(i!=n-1) printf(" ");
        }
        printf("\n");
        
    }
}