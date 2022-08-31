#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

struct fire {
    int x,y,d,l,num;
};

int d[30][8][303][303];
int b[303][303];

vpi step;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    step.pb(mp(0,1));
    step.pb(mp(1,1));
    step.pb(mp(1,0));
    step.pb(mp(1,-1));
    step.pb(mp(0,-1));
    step.pb(mp(-1,-1));
    step.pb(mp(-1,0));
    step.pb(mp(-1,1));
    int n;
    cin>>n;
    vi t(n);
    forn(i,0,n) {
        cin>>t[i];
    }
    deque<fire> q;
    d[0][0][151][150] = 1;
    fire s;
    s.x = 151;
    s.y = 150;
    s.num = 0;
    s.d = 0;
    q.pb(s);
    while(!q.empty()) {
        fire u = q.front();
        q.pop_front();
        int x = u.x;
        int y = u.y;
        forn(i,0,t[u.num]) {
            x += step[u.d].first;
            y += step[u.d].second;
        }
        if(u.num == n-1) continue;
        s.x = x;
        s.y = y;
        s.num = u.num+1;
        s.d = (u.d + 7)%8;
        if(d[s.num][s.d][x][y] == 0) {
            d[s.num][s.d][x][y] = 1;
            q.pb(s);
        }
        s.d = (s.d+2)%8;
        if(d[s.num][s.d][x][y] == 0) {
            d[s.num][s.d][x][y] = 1;
            q.pb(s);
        }
    }
    forn(l,0,n) {
        forn(dir,0,8) {
            forn(x,0,303) {
                forn(y,0,303) {
                    if(d[l][dir][x][y]) {
                        forn(i,1,t[l]+1) {
                            b[x+i*step[dir].first][y+i*step[dir].second] = 1;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    forn(i,0,303) forn(j,0,303) ans += b[i][j];
//    forn(i,150-10, 150+10) {
//        forn(j,150-10, 150+10) {
//            cout<<b[i][j];
//        }
//        cout<<endl;
//    }
    cout << ans;
    
}