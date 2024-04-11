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

class Action{
public:
    int tp = -1;
    int shoot;
    int dx;
    Action(int tp, int shoot, int dx) : tp(tp), shoot(shoot), dx(dx) {};
    Action() {};
};

vi pos;

int to(int x) {
    return lower_bound(all(pos), x) - pos.begin();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m1,m2,t;
    scanf("%d %d %d %d", &n, &m1, &m2, &t);
    set<int> c;
    c.insert(0);
    readv(v1, m1);
    readv(v2, m2);
    sort(all(v1));
    sort(all(v2));
//    map<int, int> tp;
    for(auto x : v1) c.insert(x);
    for(auto x : v2) c.insert(x);
    for(auto x : v1) c.insert(x+1);
    for(auto x : v2) c.insert(x+1);
    c.insert(n+1);
//    map<int, int> to;
    int pt = 0;
    
    for(auto x : c) pos.pb(x), pt++;
    const int inf = 1e9 + 1000;
    vi b1(pt, -inf);
    vi b2(pt, -inf);
    vi vtp(pt, 0);
    for(auto x : v1) vtp[to(x)] += 1;
    for(auto x : v2) vtp[to(x)] += 2;
    vector<Action> p1(pt);
    vector<Action> p2(pt);
    b1[0] = -t;
    b2[0] = -t;
    p2[0] = Action(0,0,0);
    forn(i,0,pt-1) {
        int x = pos[i];
        if((vtp[i] & 1) == 0 && b1[i] < b2[i] && b1[i] < 0) {
            b1[i] = min(b2[i], 0);
            p1[i] =  Action(0,0,0);
        }
        if((vtp[i] & 2) == 0 && b2[i] < b1[i] && b2[i] < 0) {
            b2[i] = min(b1[i], 0);
            p2[i] =  Action(0,0,0);
        }
        auto itn1 = upper_bound(all(v1), x);
        auto itn2 = upper_bound(all(v2), x);
        if(itn1 != v1.end() && b1[i] != -inf) {
            int nw1 = *itn1;
            int i1 = to(nw1);
            int d = nw1 - x;
            if (b1[i] + d - 1 >= 0 && b1[i1] < b1[i] + d - t) {
                b1[i1] = b1[i] + d - t;
                p1[i1] = Action(1, x - b1[i], x);
            }
        }
        if(itn2 != v2.end() && b2[i] != -inf) {
            int nw2 = *itn2;
            int i2 = to(nw2);
            int d = nw2 - x;
            if (b2[i] + d - 1 >= 0 && b2[i2] < b2[i] + d - t) {
                b2[i2] = b2[i] + d - t;
                p2[i2] = Action(1, x - b2[i], x);
            }
        }
        int nx = pos[i+1];
        if(b1[i] != -inf && (vtp[i+1] & 1) == 0 && b1[i+1] < b1[i] + nx - x) {
            b1[i+1] = b1[i] + nx - x;
            p1[i+1] = Action(2,0,x);
        }
        if(b2[i] != -inf && (vtp[i+1] & 2) == 0 && b2[i+1] < b2[i] + nx - x) {
            b2[i+1] = b2[i] + nx - x;
            p2[i+1] = Action(2,0,x);
        }
    }
    int curx = n+1;
    int cury = 1;
    if(b1[pt-1] == -inf && b2[pt-1] == -inf) {
        cout << "No";
        return 0;
    }
    if(b1[pt-1] == -inf) cury = 2;
    vi moves;
    vpi shoot;
    while(curx != 0 || cury != 1) {
        int ind = to(curx);
        if(cury == 1) {
            if(p1[ind].tp == 2) curx = p1[ind].dx;
            else if(p1[ind].tp == 0) {
                moves.pb(curx);
                cury = 2;
            }
            else {
                shoot.pb(mp(p1[ind].shoot, 1));
                curx = p1[ind].dx;
            }
        }
        else if(cury == 2) {
            if(p2[ind].tp == 2) curx = p2[ind].dx;
            else if(p2[ind].tp == 0) {
                moves.pb(curx);
                cury = 1;
            }
            else {
                shoot.pb(mp(p2[ind].shoot, 2));
                curx = p2[ind].dx;
            }
        }
    }
    reverse(all(moves));
    reverse(all(shoot));
    printf("Yes\n");
    printf("%d\n", (int)moves.size());
    for(auto x : moves) printf("%d ", x);
    printf("\n");
    printf("%d\n", (int)shoot.size());
    for(auto x : shoot) printf("%d %d\n", x.first, x.second);
    printf("\n");
}