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
    int n,k;
    scanf("%d %d", &n, &k);
    readv(q,n);
    readv(a,n);
    vi qm(n);
    forn(i,0,n) q[i]--, a[i]--;
    forn(i,0,n) qm[q[i]] = i;
    vi cur;
    forn(i,0,n) cur.pb(i);
    int id = 1;
    forn(i,0,n) if(a[i]!=i) id= 0;
    if(id) {
        cout<<"NO";
        return 0;
    }
    id = 1;
    forn(i,0,n) if(a[i]!=q[i]) id= 0;
    forn(i,0,n) if(a[i]!=qm[i]) id= 0;
    if(id && k>1) {
        cout<<"NO";
        return 0;
    }
    forn(i,0,k) {
        vi ncur(n);
        forn(i,0,n) ncur[i] = cur[qm[i]];
        cur = ncur;
    }
    forn(iaffa,0,k+1) {
        int g = 1;
        forn(i,0,n) if(cur[i]!=a[i]) g=0;
        if(g) {
            printf("YES");
            return 0;
        }
        vi ncur(n);
        forn(i,0,n) ncur[i] = cur[q[q[i]]];
        cur = ncur;
    }
    printf("NO");
//    int num = 0;
//    vpi pos(n, mp(-1, -1));
//    vpi pos2(n, mp(-1, -1));
//    vi sz;
//    vvi cl;
//    forn(i,0,n) {
//        cl.pb(vi());
//        if(pos[i] != mp(-1, -1)) continue;
//        int cur = i;
//        int cnt = 0;
//        do {
//            cl.back().pb(cur);
//            pos[cur] = mp(num, cnt++);
//            cur = q[cur];
//        } while(cur != i);
//        sz.pb(cnt);
//        num++;
//    }
//    int num2 = 0;
//    vi shift(n, -1);
//    const int INF = 1e9;
//    forn(i,0,n) {
//        if(pos2[i] == mp(-1, -1));
//        int cur = i;
//        int cnt = 0;
//        int ss = INF;
//        int gr = INF;
//        do {
//            if(gr != INF && pos[cur].first != gr) {
//                cout<<"NO";
//                return 0;
//            }
//            gr = pos[cur].first;
//            int ns = cnt - pos[cur].second;
//            if(ns < 0) ns += sz[gr];
//            if(ss!=INF && ss!=ns) {
//                cout<<"NO";
//                return 0;
//            }
//            ss = ns;
//            shift[cur] = ss;
//            pos2[cur] = mp(num2, cnt++);
//            cur = a[cur];
//        } while(cur != i);
//        num2++;
//    }
//    forn(i,0,num) {
//        int man = cl[i][0];
//        for(auto x : cl[i]) if(shift[man] != shift[x]) {
//            cout<<"NO";
//            return 0;
//        }
//        int t1 = shift[man];
//        int t2 = sz[i] - t1;
//        printf("%d %d\n", t1, sz[i]);
//    }
}