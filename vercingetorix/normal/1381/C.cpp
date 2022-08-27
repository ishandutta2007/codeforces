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
set<pi> q;
vi cnt;
void dec(int i) {
    auto it = q.find(mp(-cnt[i], i));
    q.erase(it);
    cnt[i]--;
    q.insert(mp(-cnt[i], i));
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
        int n,x,y;
        scanf("%d %d %d", &n, &x,&y);
        readv(b,n);
        forn(i,0,n) b[i] -- ;
        cnt = vi(n+1, 0);
        vvi pos(n+1);
        forn(i,0,n) pos[b[i]].pb(i);
        forn(i,0,n) cnt[b[i]] ++;
        int pt = 0;
        while(cnt[pt]>0) pt++;
        q.clear();
        forn(i,0,n+1) q.insert(mp(-cnt[i], i));
        vi ans(n, -1);
        int let = n;
        while(x > 0) {
            int col = q.begin()->second;
            int ind = pos[col].back();
            ans[ind] = col;
            pos[col].pop_back();
            dec(col);
            x--;
            y--;
            let--;
        }
        if(n>1) {
            while(y>0) {
                auto it = q.begin();
                int col1 = it->second;
                it++;
                if(it->first == 0) break;
                int col2 = it->second;
                int pos1 = pos[col1].back();
                int pos2 = pos[col2].back();
                pos[col1].pop_back();
                pos[col2].pop_back();
                if(let == 3 && y == 3 && pos[col1].empty()) {
                    it++;
                    int col3 = it->second;
                    int pos3 = pos[col3].back();
                    pos[col3].pop_back();
                    ans[pos1] = col2;
                    ans[pos2] = col3;
                    ans[pos3] = col1;
                    y-=3;
                    let-=3;
                    break;
                }
                dec(col1);
                dec(col2);
                ans[pos1] = col2;
                let--;
                y--;
                if(y>0) {
                    ans[pos2] = col1;
                    y--;
                    let--;
                }
            }
        }
        forn(i,0,n) {
            if(ans[i] == -1) ans[i] = pt;
            ans[i]++;
        }
        if(x>0 || y>0) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            forn(i,0,n) printf("%d ", ans[i]);
            printf("\n");
        }
    }
    
}