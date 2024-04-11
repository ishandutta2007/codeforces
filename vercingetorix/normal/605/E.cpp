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
const double eps = 1e-12;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vvi a(n, vi(n));
    forn(i,0,n) forn(j,0,n) scanf("%d", &a[i][j]);
    vi done(n,0);
    done[n-1] = 0;
    vd m(n);
    vd fp(n);
    m[n-1] = 0;
    done[n-1] = 1;
    forn(i,0,n-1) {
        if(a[i][n-1] == 0) {
            fp[i] = 1;
        }
        else {
            fp[i] = 1-double(a[i][n-1])/100;
            m[i] = double(a[i][n-1])/100;
        }
    }
    forn(it,0,n-1) {
        int best = -1;
        double ev = 1e100;
        forn(i,0,n) {
            if(done[i]) continue;
            if(fp[i] > 1-eps) continue;
            if(m[i]/(1-fp[i]) + fp[i]/(1-fp[i]) < ev) {
                ev = m[i]/(1-fp[i]) + fp[i]/(1-fp[i]);
                best = i;
            }
        }
        if(best == -1) break;
        m[best] = ev;
        done[best] = 1;
        forn(i,0,n) {
            if(done[i]) continue;
            m[i] += (1+m[best])*fp[i]*a[i][best]/100;
            fp[i] *= 1-double(a[i][best])/100;
        }
        
    }
    printf("%.10lf", m[0]);
    
    
}