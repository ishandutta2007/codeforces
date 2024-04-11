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

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int A = 1024;
    vi cnt(A);
    int n,k,x;
    scanf("%d %d %d", &n, &k, &x);
    forn(i,0,n) {
        int a;
        scanf("%d", &a);
        cnt[a] ++;
    }
    forn(i,0,k) {
        vi ncnt(A,0);
        int s = 0;
        forn(j,0,A) {
            int l = cnt[j];
            if((l&1)==0) {
                ncnt[j] += l/2;
                ncnt[j^x]+=l/2;
            }
            else {
                ncnt[j] += (s+l)/2;
                ncnt[j^x] += (1-s+l)/2;
                s=1-s;
            }
        }
        cnt = std::move(ncnt);
    }
    vi u;
    forn(i,0,A) if(cnt[i]) u.pb(i);
    cout<<u.back()<<' '<<u[0];
    
}