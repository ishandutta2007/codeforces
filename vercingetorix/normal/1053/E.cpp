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
const int N = 500500;
int last[2*N];
int nxt[2*N];
int taken[N];
int n;
int a[2*N];
vi fr;

void nope() {
    cout<<"no";
    exit(0);
}

vector<pi> lol;

void add(pi x) {
    int k = lol.size();
    if(lol.size() < 2 || lol.back().second == 0) lol.pb(x);
    else if(x.second == 0) {
        if(lol[k-2].second == 0) lol.pb(x);
        else {
            a[x.first] = lol[k-2].second;
            lol.pop_back();
        }
    }
    else {
        if(lol[k-2].second == 0) {
            lol.pop_back();
            a[lol.back().first] = x.second;
            lol.back().second = x.second;
            x = lol.back();
            lol.pop_back();
            add(x);
        }
        else lol.pb(x);
    }
}

void solve1(vpi & q, int out) {
    if(out == -1) {
        if(q[0].second != 0 && q.back().second != 0 && q[0].second != q.back().second) nope();
        if(q[0].second == 0 && q.back().second == 0) {
            int cnt = 0;
            for(auto x : q) if(x.second != 0) cnt++;
            if(cnt*2 < q.size()) {
                if(fr.empty()) nope();
                int ss = fr.back();
                fr.pop_back();
                q[0].second = ss;
                q.back().second = ss;
            }
        }
        int ss = max(q[0].second, q.back().second);
        if(ss > 0) {
            q[0].second = ss;
            q.back().second = ss;
            a[q[0].first] = ss;
            a[q.back().first] = ss;
            vpi nq;
            for(int i = 1; i+1<q.size(); i++) nq.pb(q[i]);
            solve1(nq, ss);
            return;
        }
    }
    int cnt = 0;
    for(auto x : q) if(x.second != 0) cnt++;
    if(cnt*2>q.size()+1) nope();
    int pt = 0;
    while(cnt*2 < q.size()) {
        while(q[pt].second != 0) pt++;
        if(fr.empty()) nope();
        a[q[pt].first] = fr.back();
        q[pt].second = fr.back();
        fr.pop_back();
        cnt++;
    }
    lol.clear();
    lol.pb(mp(-1, out));
    for(auto x : q) add(x);
}

void go(int l, int r) {
    if(l>r) nope();
    if((r-l)%2 == 1) nope();
    vpi q;
    for(int i = l; i <= r; i++) {
        if(a[i] != 0) {
            while(nxt[i] != -1) {
                if(nxt[i] > r) nope();
                go(i+1, nxt[i]-1);
                i = nxt[i];
            }
            if(last[a[i]] > r) nope();
        }
        q.pb(mp(i, a[i]));
    }
    if(l == 0) solve1(q, -1);
    else solve1(q, a[l-1]);
    
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,2*n-1) scanf("%d", &a[i]);
    for(int i = 2*n-2; i >= 0; i--) {
        if(a[i] > 0 && last[a[i]] != 0) nxt[i] = last[a[i]];
        else nxt[i] = -1;
        last[a[i]] = i;
    }
    forn(i,0,2*n-1) last[a[i]] = i;
    forn(i,0,2*n-1) taken[a[i]] = 1;
    forn(i,1,n+1) if(taken[i] == 0) fr.pb(i);
    go(0,2*n-2);
    forn(i,0,2*n-1) if(a[i] == -1) nope();
    printf("yes\n");
    forn(i,0,2*n-1) printf("%d ", a[i]);
    
    
}