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

deque<pi> sm(string s) {
    int pt = 0;
    deque<pi> ret;
    while(pt<s.size()) {
        int pr = pt+1;
        while(pr<s.size() && s[pr] == s[pt]) pr++;
        ret.pb(mp(pr-pt, s[pt]-'a'));
        pt = pr;
    }
    return ret;
}
deque<pi> qa,qb;
vpi q;

void go(int ta, int tb) {
    vpi ea,eb;
    int la = 0;
    int lb = 0;
    forn(i,0,ta) {
        ea.pb(qa.front());
        la+=qa.front().first;
        qa.pop_front();
    }
    forn(i,0,tb) {
        eb.pb(qb.front());
        lb+=qb.front().first;
        qb.pop_front();
    }
    q.pb(mp(la,lb));
    if(!ea.empty()) {
        if(qb.empty()) qb.pb(mp(0, ea.back().second));
        qb[0].first += ea.back().first;
        ea.pop_back();
        while(!ea.empty()) {
            qb.push_front(ea.back());
            ea.pop_back();
        }
    }
    if(!eb.empty()) {
        if(qa.empty()) qa.pb(mp(0, eb.back().second));
        qa[0].first += eb.back().first;
        eb.pop_back();
        
        while(!eb.empty()) {
            qa.push_front(eb.back());
            eb.pop_back();
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[500500];
    scanf("%s",c);
    string a(c);
    scanf("%s",c);
    string b(c);
    qa = sm(a);
    qb = sm(b);
    
    
    if(qb.size() > qa.size()) {
        if(qa.size() > 1) {
            int tka = 1;
            int tkb = 1;
            if(qa[0].second == qb[0].second) tkb = 2;
            int as = qa.size();
            int bs = qb.size();
            while(as-tka+tkb-1 +2 < bs-tkb+tka-1) tkb+=2;
            go(tka, tkb);
        }
        else {
            int tkb = qb.size() / 2;
            int tka = 0;
            if(qa[0].second == qb[tkb].second) tka = 1;
            go(tka, tkb);
        }
    }
    else if(qa.size() > qb.size()) {
        swap(qa,qb);
        if(qa.size() > 1) {
            int tka = 1;
            int tkb = 1;
            if(qa[0].second == qb[0].second) tkb = 2;
            int as = qa.size();
            int bs = qb.size();
            while(as-tka+tkb-1 +2 < bs-tkb+tka-1) tkb+=2;
            go(tka, tkb);
        }
        else {
            int tkb = qb.size() / 2;
            int tka = 0;
            if(qa[0].second == qb[tkb].second) tka = 1;
            go(tka, tkb);
        }
        swap(qa,qb);
        swap(q[0].first, q[0].second);
    }
    while(qa.size() > 1 || qb.size() > 1) {
        if(qa[0].second == qb[0].second) {
            if(qa.size() > qb.size()) go(1,0);
            else go(0,1);
        }
        else go(1,1);
    }
    
    printf("%d\n", q.size());
    for(auto x : q) printf("%d %d\n", x.first, x.second);
}