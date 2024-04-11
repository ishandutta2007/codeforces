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
vi ans ;
vi a;
void go(int i) {
    ans.pb(i+1);
    int mem = a[i+2];
    a[i+2] = a[i+1];
    a[i+1] = a[i];
    a[i] = mem;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        ans.clear();
        int n;
        read(n);
        a = vi(n);
        forn(i,0,n) scanf("%d", &a[i]);
//        vi ans;
        for(int to = n-1; to >= 2; to--) {
            int ind = 0;
            forn(i,0,to+1) if(a[i] > a[ind]) ind = i;
            if(ind == 0) {
                go(0);
                ind++;
            }
            forn(i,ind,to) go(i-1);
        }
        if(a[0] > a[1]) {
            if(a[0]==a[2]) {
                go(0);
                go(0);
            }
            else {
                forn(i,2,n-1) {
                    if(a[i]==a[i+1]) {
                        for(int j = (i-1);j>=0;j--) go(j);
                        break;
                    }
                }
            }
        }
        if(a[0]>a[1]) printf("-1\n");
        else {
            printf("%d\n", (int)ans.size());
            for(auto x : ans) printf("%d ", x);
            printf("\n");
            
        }
    }
    
}