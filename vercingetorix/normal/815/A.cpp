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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n, vi(m,0));
    vs ans;
    int sum = 0;
    forn(i,0,n) {
        forn(j,0,m) {
            scanf("%d", &a[i][j]);
            sum+=a[i][j];
        }
    }
    
    while(sum > 0) {
        pair<int, pi> mn = mp(1000, mp(0,0));
        pair<int, pi> mx = mp(-1, mp(0,0));
        bool did = false;
        forn(i,0,n) {
            forn(j,0,m) {
                mn = min(mn, mp(a[i][j], mp(i,j)));
                mx = max(mx, mp(a[i][j], mp(i,j)));
                if(mx.first > mn.first) {
                    pi p = mn.second;
                    pi q = mx.second;
                    if (mx.first >  a[p.first][q.second]) {
                        ans.pb("row " + to_string(q.first + 1));
                        forn(k,0,m) {
                            a[q.first][k]--;
                            if(a[q.first][k] < 0) {
                                cout << -1;
                                return 0;
                            }
                        }
                        sum -= m;
                    }
                    else if (mn.first < a[p.first][q.second]) {
                        ans.pb("col " + to_string(q.second + 1));
                        forn(k,0,n) {
                            a[k][q.second]--;
                            if(a[k][q.second] < 0) {
                                cout << -1;
                                return 0;
                            }
                        }
                        sum -= n;
                    }
                    did = true;
                    break;
                }
            }
            if(did) break;
        }
        if(did == false) {
            int a = mn.first;
            if (m > n) {
                forn(i,0,n) {
                    forn(it, 0, a) {
                        ans.pb("row " + to_string(i+1));
                    }
                }
            }
            else {
                forn(i,0,m) {
                    forn(it, 0, a) {
                        ans.pb("col " + to_string(i+1));
                    }
                }
            }
            sum = 0;
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%s\n", x.c_str());
    
    
}