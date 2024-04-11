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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string a;
    getline(cin, a);
    int n;
    int m = a.size();
    reverse(all(a));
    vi c(10);
    scanf("%d\n", &n);
    vs b(n);
    forn(i,0,n) {
        getline(cin, b[i]);
        reverse(all(b[i]));
    }
    forn(i,0,10) scanf("%d", &c[i]);
    vvi ord(1100);
    forn(i,0,n) ord[0].pb(i);
    forn(d,1,1010) {
        vi pos(n);
        vi nd(n,0);
        forn(i,0,n) pos[ord[d-1][i]] = i;
        forn(i,0,n) if(b[i].size() >= d) nd[i]=b[i][d-1]-'0';
        forn(dd,0,10) {
            forn(i,0,n) if(nd[ord[d-1][i]] == dd) ord[d].pb(ord[d-1][i]);
        }
    }
//    forn(d,0,5) {
//        for(auto x : ord[d]) cout<<b[x]<<' ';
//        cout<<endl;
//    }
    int INF = 2e9;
    vvi d(1100, vi(1100,-INF));
    d[0][0] = 0;
    forn(i,0,m) {
        vi cnt(10,0);
        forn(j,0,n) {
            if(b[j].size() <= i) cnt[0]++;
            else cnt[b[j][i] - '0']++;
        }
//        int add = 0;
//        forn(j,0,10) add += cnt[j]*c[j];
        int per = 0;
        forn(j,0,n+1) {
            int cp = per;
            forn(dig,0,10) {
                if(a[i] != '?' && a[i] != ('0'+dig)) {
                    cp += cnt[9-dig];
                    continue;
                }
                if(i == m-1 && dig == 0) {
                    cp += cnt[9-dig];
                    continue;
                }
                int add = 0;
                forn(dwas,0,10) add += cnt[dwas] * c[(dwas+dig)%10];
                d[i+1][cp] = max(d[i+1][cp], d[i][j] + add);
                cp += cnt[9-dig];
            }
            if (j==n) break;
            int inc = ord[i][n-1-j];
            int dig = 0;
            if(b[inc].size() > i) dig = b[inc][i]-'0';
            if(dig == 9) per++;
            cnt[dig]--;
            cnt[(dig+1)%10]++;
        }
    }
    int best = 0;
    int over = 0;
    forn(i,0,n) {
        forn(k,m,b[i].size()) over += c[b[i][k]-'0'];
    }
    forn(i,0,n+1) {
        best = max(d[m][i] + over, best);
        if(i==n) break;
        int ind = ord[m][n-1-i];
        forn(k,m,b[ind].size()) over -= c[b[ind][k]-'0'];
        int carry = 1;
        forn(k,m,b[ind].size()) {
            int nd = (b[ind][k]-'0') + carry;
            if(nd == 10) {
                nd = 0;
            }
            else carry = 0;
            over += c[nd];
        }
        if(carry == 1) over+=c[1];
    }
    cout<<best;
    
    
}