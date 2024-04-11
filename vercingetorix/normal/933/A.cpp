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

//int get(vi a, int n) {
//    vpi x;
//    forn(i,0,n) {
//        if(i==0 || a[i]!=a[i-1]) x.pb(mp(a[i],1));
//        else x.back().second++;
//    }
//    if(x.size() <= 3) {
//        return n;
//    }
//    int k = x.size();
//    int ans = 0;
//    forn(i,0,k-2) {
//        ans = max(ans, x[i].second+x[i+1].second+x[i+2].second);
//    }
//    forn(i,0,k-3) {
//        if(x[i].first == 1) ans = max(ans, x[i].second+x[i+1].second+x[i+2].second + x[i+3].second);
//    }
//    forn(i,0,k) {
//        if(x[i].first == 1) {
//            forn(j,i+1,k-1) {
////                if(x[j].first == 2) {
//                    ans = max(ans, x[i].second + x[j].second + x[j+1].second);
////                }
//            }
//            if(i!=k-1) ans = max(ans, x[i].second + x[k-1].second);
//        }
//        if(x[i].first == 1) {
//            forn(j,i+2,k) {
//                if(x[j].first == 2) {
//                    ans = max(ans, x[i].second + x[j].second + x[i+1].second);
//                }
//            }
//        }
//        if(x[i].first == 2) {
//            forn(j,i+2,k) {
//                if(x[j].first == 2) {
//                    ans = max(ans, x[i].second + x[i+1].second + x[j].second);
//                }
//            }
//        }
//    }
//    return  ans;
//}
//
//int get2(vi a, int n) {
//    vi was = a;
//    int ans = 0;
//    forn(i,0,n) {
//        forn(j,i+1,n) {
//            vpi x;
//            reverse(a.begin() + i, a.begin() + j + 1);
////            forn(i,0,n) cout<<a[i]; cout<<endl;
//            forn(i,0,n) {
//                if(i==0 || a[i]!=a[i-1]) x.pb(mp(a[i],1));
//                else x.back().second++;
//            }
//            int k = x.size();
//            if(k == 1) return n;
//            forn(t,0,k-1) {
//                if(x[t].first == 1) ans = max(ans, x[t].second + x[t+1].second);
//            }
//            forn(t,0,k) ans = max(ans, x[t].second);
//            
//            a = was;
//        }
//    }
//    return ans;
//}

int d2[2000][2000];
int d1[2000][2000];
int d12[2000][2000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    readv(a,n);
//    int ans = 0;
    forn(i,0,n) {
        d12[i][i] = 1;
        if(a[i]==2) d2[i][i] = 1;
        if(a[i]==1) d1[i][i] = 1;
    }
    forn(s,0,n) {
        forn(e,s+1,n) {
            d2[s][e] = d2[s][e-1];
            d1[s][e] = d1[s][e-1];
            if(a[e] == 2) d2[s][e]++;
            if(a[e] == 1) d1[s][e]++;
            d12[s][e] = d12[s][e-1];
            if(a[e] == 1) d12[s][e]++;
            d12[s][e] = max(d12[s][e], d2[s][e]);
        }
    }
    int ans = 0;
    forn(s,0,n) {
        forn(e,s,n) {
            int cand = d12[s][e];
            if(s>0) cand += d1[0][s-1];
            if(e<n-1) cand+=d2[e+1][n-1];
            ans = max(ans, cand);
        }
    }
    cout<<ans;
    
//    int k = 20;
//    forn(u,0,1<<k) {
//        int w = u;
//        vi a;
//        forn(i,0,k) {
//            a.pb(w%2+1);
//            w/=2;
//        }
//        if(get(a,k) != get2(a,k)) {
//            forn(i,0,k) cout<<a[i];
//            cout<<endl;
//            cout<<get(a, k);
//            cout<<endl;
//            cout<<get2(a, k);
//            cout<<endl;
//            exit(0);
//        }
//    }
//    int ans = get(a, n);
//    cout<<ans;
}