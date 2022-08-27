#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
int vx,vy,sx,sy;

const int A = 210;
const int B = 105;
vpi p[A];
vvi b(A, vi(A,0));
vpi dir;
vpi obs;

string ans;



char add(pi x) {
    if(x.first == -1) return 'L';
    else if(x.first == 1) return 'R';
    else if(x.second == -1) return 'D';
    else return 'U';
}

void fin() {
    printf("%s\n", ans.c_str());
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(x,-1,2) forn(y,-1,2) if(x*y==0 && x+y!=0) dir.pb(mp(x,y));
    scanf("%d %d %d %d", &vx, &vy, &sx, &sy);
    vx+=B;
    vy+=B;
    sx+=B;
    sy+=B;
    forn(i,0,A) p[i] = vpi(A, mp(0,0));
    int m;
    read(m);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        b[B+x][B+y] = 1;
        obs.pb(mp(B+x, B+y));
    }
    deque<pi> q;
    q.pb(mp(vx, vy));
    p[vx][vy] = mp(42, 42);
    while(!q.empty()) {
        int x = q[0].first;
        int y = q[0].second;
        q.pop_front();
        for(auto to : dir) {
            int x2 = x + to.first;
            int y2 = y + to.second;
            if(x2 < 0 || y2<0 || x2 >=A || y2>=A || b[x2][y2] == 1 || p[x2][y2] != mp(0,0)) continue;
            p[x2][y2] = to;
            q.pb(mp(x2,y2));
        }
    }
    if(p[sx][sy] == mp(0,0) || m == 0) {
        cout<<-1;
        exit(0);
    }
    vpi path;
    int cx = sx;
    int cy = sy;
    while(cx != vx || cy != vy) {
        path.pb(p[cx][cy]);
        cx-= path.back().first;
        cy -= path.back().second;
    }
    reverse(all(path));
    
    while(1) {
        vpi npath;
        for(auto st : path) {
            ans.pb(add(st));
            int sx2 = sx + st.first;
            int sy2 = sy + st.second;
            vx += st.first;
            vy += st.second;
            if(sx2 >= 0 && sy2 >= 0 && sx2<A &&sy2<A && b[sx2][sy2]) {
                
            }
            else {
                sx = sx2;
                sy = sy2;
                npath.pb(st);
            }
        }
        if(vx<0 && sx < 0) break;
        if(vx>=A && sx >= A) break;
        if(vy<0 && sy < 0) break;
        if(vy>=A && sy >= A) break;
        path = npath;
        if(path.empty()) fin();
        if(vx == sx && vy == sy) fin();
    }
    auto neut = [&] () {
        while((vx>=0 && vx < A) || (sx >= 0 && sx <A)) {
            ans.pb('R');
            vx++;
            sx++;
        }
        while((vy>=0 && vy < A) || (sy >= 0 && sy <A)) {
            ans.pb('U');
            vy++;
            sy++;
        }
    };
    neut();
    if(vx < sx) {
        while(vx >= 0 || sx>=0) {
            ans.pb('L');
            vx--;
            sx--;
        }
        pi mn = obs[0];
        for(auto x : obs) mn = min(mn, x);
        while(sx + 1 < mn.first) {
            ans.pb('R');
            sx++;
            vx++;
        }
        while(sy < mn.second) {
            ans.pb('U');
            sy ++;
            vy++;
        }
        while(sy > mn.second) {
            ans.pb('D');
            sy--;
            vy--;
        }
        while(vx < sx) {
            ans.pb('R');
            vx++;
        }
        while(sx >= 0) {
            ans.pb('L');
            sx--;
            vx--;
        }
        neut();
    }
    if(vx > sx) {
        while(vx < A || sx<A) {
            ans.pb('R');
            vx++;
            sx++;
        }
        pi mn = obs[0];
        for(auto x : obs) mn = max(mn, x);
        while(sx - 1 > mn.first) {
            ans.pb('L');
            sx--;
            vx--;
        }
        while(sy < mn.second) {
            ans.pb('U');
            sy ++;
            vy++;
        }
        while(sy > mn.second) {
            ans.pb('D');
            sy--;
            vy--;
        }
        while(vx > sx) {
            ans.pb('L');
            vx--;
        }
        while(sx < A) {
            ans.pb('R');
            sx++;
            vx++;
        }
        neut();
    }
    if(vy < sy) {
        while(vy >= 0 || sy>=0) {
            ans.pb('D');
            vy--;
            sy--;
        }
        pi mn = obs[0];
        for(auto x : obs) if(x.second < mn.second) mn = x;
        while(sy + 1 < mn.second) {
            ans.pb('U');
            sy++;
            vy++;
        }
        while(sx < mn.first) {
            ans.pb('R');
            sx ++;
            vx++;
        }
        while(sx > mn.first) {
            ans.pb('L');
            sx--;
            vx--;
        }
        while(vy < sy) {
            ans.pb('U');
            vy++;
        }
        while(sy >= 0) {
            ans.pb('D');
            sy--;
            vy--;
        }
        neut();
    }
    if(vy > sy) {
        while(vy < A || sy < A) {
            ans.pb('U');
            vy++;
            sy++;
        }
        pi mn = obs[0];
        for(auto x : obs) if(x.second > mn.second) mn = x;
        while(sy - 1 > mn.second) {
            ans.pb('D');
            sy--;
            vy--;
        }
        while(sx < mn.first) {
            ans.pb('R');
            sx ++;
            vx++;
        }
        while(sx > mn.first) {
            ans.pb('L');
            sx--;
            vx--;
        }
        while(vy > sy) {
            ans.pb('D');
            vy--;
        }
        while(sy < A) {
            ans.pb('U');
            sy++;
            vy++;
        }
        neut();
    }
    fin();

    
}