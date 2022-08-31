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
const int A = 1000000;
int gr[A];

int d2[32];
int d21[32];
set<int> done;
map<int, int> gres;

int get(int pos) {
    if(pos<A) return gr[pos];
    if(done.find(pos) != done.end()) return gres[pos];
    vi can(32,0);
    forn(bit,1,30) {
        if(1<<bit > pos) break;
        int was = (pos & d21[bit]) | (pos >> bit);
        can[get(was)] = 1;
    }
    forn(i,0,32) if(can[i] == 0) {
        done.insert(pos);
        gres[pos] = i;
        return i;
    }
    return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,32) {
        d2[i] = 1<<i;
        d21[i] = (1<<i) - 1;
    }
    forn(pos,2,A) {
        vi can(32,0);
        forn(bit,1,30) {
            if(1<<bit > pos) break;
            int was = (pos & d21[bit]) | (pos >> bit);
            can[gr[was]] = 1;
        }
        forn(i,0,32) if(can[i] == 0) {
            gr[pos] = i;
            break;
        }
    }
    const int LIMIT = 100000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    map<int, set<int>> prset;
    int n;
    scanf("%d", &n);
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        for(auto md : p) {
            int cnt  = 0;
            while(x%md == 0) {
                x/=md;
                cnt++;
            }
            if(cnt > 0) prset[md].insert(cnt);
        }
        if(x>1) prset[x].insert(1);
    }
    int res = 0;
    for(auto st : prset) {
        int pos = 0;
        for(auto bit : st.second) pos |= 1<<bit;
        res = res ^ get(pos);
    }
    if(res == 0) cout<<"Arpa";
    else cout<<"Mojtaba";
    
}