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
const int A = 5000;
int fa[3][A];
int a[3][A];
int b[3][A];
int cnt[3];
int fn;
int price[3];
int getprice(int num) {
    if(num*2>fn) return 1;
    else if(num*4>fn) return 2;
    else if(num*8>fn) return 3;
    else if(num*16>fn) return 4;
    else if(num*32>fn) return 5;
    else return 6;
}
int n = 0;
int n2 = 0;
int phack[3];
vi bnum[3][7];
int d[25][25][25];
int p[3];

int good[2][2][2];
int shift[3][10];
int ns = 0;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>fn;
    int nhack = 0;
    forn(i,0,fn) {
        cin>>fa[0][i]>>fa[1][i]>>fa[2][i];
        forn(j,0,3) if(fa[j][i] != 0) cnt[j]++;
        int canhack = 0;
        forn(j,0,3) if(fa[j][i] < 0) {
            canhack++;
            phack[j]++;
        }
        if(canhack > 0) {
            nhack += canhack;
            forn(j,0,3) a[j][n] = fa[j][i];
            n++;
        }
        else if(i>0) {
            forn(j,0,3) b[j][n2] = fa[j][i];
            n2++;
        }
    }
    forn(j,0,3) price[j] = getprice(cnt[j] - phack[j]);
    int me = nhack*50;
    forn(j,0,3) if(fa[j][0] > 0) me += price[j]*(250-fa[j][0]);
    int place = 1;
    forn(i,1,fn) {
        int opp = 0;
        forn(j,0,3) if(fa[j][i] > 0) opp += price[j]*(250-fa[j][i]);
        if(opp > me) place++;
    }
    if(place == 1) {
        cout<<place;
        exit(0);
    }
    forn(j,0,3) forn(left,0, min(24, phack[j]) + 1) {
        int hack = phack[j] - left;
        bnum[j][getprice(cnt[j] - hack)].pb(left);
    }
    for(p[0] = 1; p[0] < 7; p[0]++) if(!bnum[0][p[0]].empty()) for(p[1] = 1; p[1] < 7; p[1]++) if(!bnum[1][p[1]].empty()) for(p[2] = 1; p[2] < 7; p[2]++) if(!bnum[2][p[2]].empty()) {
        forn(i,0,25) forn(j,0,25) forn(k,0,25) d[i][j][k] = -500;
        d[0][0][0] = 0;
        me = 0;
        forn(j,0,3) me += 50*(phack[j]-bnum[j][p[j]][0]);
        forn(j,0,3) if(fa[j][0] > 0) me += p[j]*(250-fa[j][0]);
        int cand = 1;
        forn(i,0,n2) {
            int opp = 0;
            forn(j,0,3) if(b[j][i] > 0) opp += p[j]*(250-b[j][i]);
            if(opp > me) cand++;
        }
        int l0 = bnum[0][p[0]][0];
        int l1 = bnum[1][p[1]][0];
        int l2 = bnum[2][p[2]][0];
        int ll0 = l0;
        int ll1 = l1;
        int ll2 = l2;
        forn(i,0,n) {
            int opp = 0;
            forn(j,0,3) if(a[j][i] != 0) opp += p[j]*(250-abs(a[j][i]));
            if(opp <= me) {
                if(a[0][i] < 0) ll0--;
                if(a[1][i] < 0) ll1--;
                if(a[2][i] < 0) ll2--;
                continue;
            }
            cand++;
            int opp2 = 0;
            forn(j,0,3) if(a[j][i] > 0) opp2 += p[j]*(250-a[j][i]);
            if(opp2 > me) {
                if(a[0][i] < 0) ll0--;
                if(a[1][i] < 0) ll1--;
                if(a[2][i] < 0) ll2--;
                continue;
            }
            forn(s0,0,2) forn(s1,0,2) forn(s2,0,2) {
                good[s0][s1][s2] = 0;
                if(a[0][i] >= 0 && s0 > 0) continue;
                if(a[1][i] >= 0 && s1 > 0) continue;
                if(a[2][i] >= 0 && s2 > 0) continue;
                int opptest = opp2;
                if(s0) opptest += p[0]*(250+a[0][i]);
                if(s1) opptest += p[1]*(250+a[1][i]);
                if(s2) opptest += p[2]*(250+a[2][i]);
                if(opptest <= me && s0+s1+s2>0) {
                    good[s0][s1][s2] = 1;
                }
            }
            ns = 0;
//            for(int s0 = 1; s0 >= 0; s0--)
//                for(int s1 = 1; s1 >= 0; s1--)
//                    for(int s2 = 1; s2 >= 0; s2--) {
//                        if(s0 && good[0][s1][s2]) good[s0][s1][s2] = 0;
//                        if(s1 && good[s0][0][s2]) good[s0][s1][s2] = 0;
//                        if(s2 && good[s0][s1][0]) good[s0][s1][s2] = 0;
//                        if(good[s0][s1][s2]) {
//                            shift[0][ns] = s0;
//                            shift[1][ns] = s1;
//                            shift[2][ns] = s2;
//                            ns++;
//                        }
//                    }
            forn(s0,0,2) forn(s1,0,2) forn(s2,0,2) {
                if(s0 == 0 && good[1][s1][s2]) good[s0][s1][s2] = 0;
                if(s1 == 0 && good[s0][1][s2]) good[s0][s1][s2] = 0;
                if(s2 == 0 && good[s0][s1][1]) good[s0][s1][s2] = 0;
                if(good[s0][s1][s2]) {
                    shift[0][ns] = s0;
                    shift[1][ns] = s1;
                    shift[2][ns] = s2;
                    ns++;
                }
            }
            shift[0][ns] = (a[0][i] < 0);
            shift[1][ns] = (a[1][i] < 0);
            shift[2][ns] = (a[2][i] < 0);
//            cout<<"test chel "<<i<<'\n';
//            forn(k,0,ns) {
//                cout<<shift[0][k]<<' '<<shift[1][k]<<' '<<shift[2][k]<<'\n';
//            }
            for(int d0 = l0; d0>=0; d0--)
                for(int d1 = l1; d1>=0; d1--)
                    for(int d2 = l2; d2>=0; d2--) {
                        forn(it,0,ns+1) {
                            int nd0 = min(d0 + shift[0][it], l0);
                            int nd1 = min(d1 + shift[1][it], l1);
                            int nd2 = min(d2 + shift[2][it], l2);
                            if(nd0+nd1+nd2 > d0 + d1 +d2) {
                                d[nd0][nd1][nd2] = max(d[nd0][nd1][nd2], d[d0][d1][d2] + (it<ns));
                            }
                        }
                        d[d0][d1][d2]++;
                    }
        }
        int rev = 0;
        for(int d0 = l0; d0>=max(ll0,0); d0--)
            for(int d1 = l1; d1>=max(ll1,0); d1--)
                for(int d2 = l2; d2>=max(ll2,0); d2--)
                    rev = max(rev, d[d0][d1][d2]);
        if(rev > cand) {
            rev= rev+1-1;
        }
//        cout<<cand<<' '<<rev<<" cr\n";
        place = min(place, cand - rev);
    }
    cout<<place;
    
}