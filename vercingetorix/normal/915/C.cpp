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
vi cnt(10,0);

ll cand = 0;
bool done = false;
vi d;
int num = 0;

void go(int pos, int can) {
    if(pos == num) {
        done = true;
        return;
    }
    if(can) {
        for(int i = 9; i>=0; i--) {
            if(cnt[i] > 0) {
                cand = cand*10+i;
                cnt[i]--;
                go(pos+1,1);
                break;
            }
        }
    }
    else {
        int nd = d[pos];
        if(cnt[nd] > 0) {
            cand = cand*10 + nd;
            cnt[nd]--;
            go(pos+1, 0);
            if(done) return;
            cnt[nd]++;
            cand/=10;
        }
        for(int i = nd-1; i>=0; i--) {
            if(cnt[i] > 0) {
                cand = cand*10+i;
                cnt[i]--;
                go(pos+1,1);
                break;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll a,b;
    cin>>a>>b;
    
    while(a > 0) {
        cnt[a%10]++;
        a/=10;
        num++;
    }
    while(b>0) {
        d.pb(b%10);
        b/=10;
    }
    reverse(all(d));
    if(num<d.size()) {
        go(0, 1);
    }
    else go(0,0);
    cout<<cand;
    
}