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
vi x,y;
const ld PI = acos(ld(-1));

ld dang(int x1, int y1, int x2, int y2) {
//    ld ret = atan2(ld(y2), x2) - atan2(ld(y1), x1);
    ld ret = atan2(y2*x1-x2*y1,x1*x2+y1*y2);
//    cout<<ret<<' '<<ret2<<'\n';
    if(ret < 0) ret += 2*PI;
    return ret;
}

ld dang(pi x, pi y) {
    return dang(x.first, x.second, y.first, y.second);
}
const ld eps = 1e-12;

template <typename T>
struct sparse_table{
    vector<vector<T>> ST;
    sparse_table(const vector<T> &A){
        int N = A.size();
        int LOG = 32 - __builtin_clz(N);
        ST = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; i++){
            ST[0][i] = A[i];
        }
        for (int i = 0; i < LOG - 1; i++){
            for (int j = 0; j < N - (1 << i); j++){
                ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
            }
        }
    }
    T range_min(int L, int R){
        int d = 31 - __builtin_clz(R - L);
        return min(ST[d][L], ST[d][R - (1 << d)]);
    }
};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,100) {
        dang(1+gen()%1000, 1+gen()%1000, 1+gen()%1000, 1+gen()%1000);
    }
    
    int n;
    read(n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) scanf("%d %d", &x[i], &y[i]);
    int ans = 0;
    forn(s,0,n) {
        vpi q;
        forn(i,0,n) if(i!=s) {
            q.pb(mp(x[i]-x[s], y[i] - y[s]));
        }
        sort(all(q), [&](const pi & a, const pi & b) {
            //        return a.first.first < b.first.first;
            bool ha = a.second > 0 || (a.second == 0 && a.first > 0);
            bool hb = b.second > 0 || (b.second == 0 && b.first > 0);
            if(ha) {
                if(hb == false) return true;
                if(a.second == 0) return b.second > 0;
                else if(b.second == 0) return false;
                return ll(a.first)*b.second > ll(b.first)*a.second;
            }
            else {
                if(hb == true) return false;
                if(a.second == 0) return b.second < 0;
                else if(b.second == 0) return false;
                return ll(a.first)*b.second > ll(b.first)*a.second;
            }
        });
        reverse(all(q));
        int mid = 0;
        int l = 0;
        int r = 0;
        vi sq;
        forn(i,0,q.size()) sq.pb(-q[i].first*q[i].first-q[i].second*q[i].second);
        sparse_table<int> sp(sq);
        
        while(1) {
            int l1 = l-1;
            if(l1<0) l1+=q.size();
            if(l1 != r && dang(q[mid], q[l1]) < PI/3-eps) {
                l = l1;
            }
            else break;
        }
        while(1) {
            int r1 = r+1;
            if(r1>=q.size()) r1-=q.size();
            if(r1 != l && dang(q[r1], q[mid]) < PI/3-eps) {
                r = r1;
            }
            else break;
        }
        while(1) {
            int mn = 0;
            if(l<=r) {
                if(l > 0) mn = min(mn, sp.range_min(0, l));
                if(r < n-2) mn = min(mn, sp.range_min(r+1, n-1));
            }
            else {
                if(r+1 < l) mn = min(mn, sp.range_min(r+1, l));
            }
            ans = max(ans, min(-mn, -sq[mid]));
            if(mid == n-2) break;
            mid++;
            if(mid == l) {
                l++;
                if(l >= q.size()) l-=q.size();
                r++;
            }
            else if(r == mid-1) {
                r++;
            }
            while(dang(q[mid], q[l]) >= PI/3-eps) {
                l++;
                if(l>=q.size()) l-=q.size();
            }
            while(1) {
                int r1 = r+1;
                if(r1>=q.size()) r1-=q.size();
                if(r1 != l && dang(q[r1], q[mid]) < PI/3-eps) {
                    r = r1;
                }
                else break;
            }
        }
    }
    printf("%.10lf", double(sqrt(ld(ans)))/2);
    
    
}