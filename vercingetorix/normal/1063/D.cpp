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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
void nope() {
    cout<<-1;
    exit(0);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,l,r,k;
    cin>>n>>l>>r>>k;
    ll a= r-l+1;
    if(a<=0) a+=n;
    ll b = n-a;
    if(k<a) nope();
    k-=a;
    const ll A = 1000000;
    ll ans = -1;
    if(n <= A) {
        forn(ab,0,n+1) {
            ll a1 = k % (n+ab);
            if(a1 <= a && a1<=ab && a1+b>=ab) ans = ab;
            a1 = (k+1)%(n+ab);
            if(a1>=1 && a1 <= a && a1 <= ab && a1+b>=ab) ans = ab;
        }
        cout<<ans;
        exit(0);
    }
    else {
        ll ans = -1;
        if(a>=k) ans = max(ans, b+k);
        if(a-1>=k) ans = max(ans, b+k+1);
        forn(l,1,A) {
            if(n*l > k) break;
            if(n*2*l+a<k) continue;
            ll r1 = k%l;
            ll C = (k - n*l - r1)/l - r1;
            if(a>=r1 && C>=0) {
                ll la2 = 0;
                ll ra2 = (a - r1)/l;
                ll r2 = C%(l+1);
                if(b >= r2) {
                    ll lb2 = 0;
                    ll rb2 = (b-r2)/(l+1);
                    ll D = (C-r2)/(l+1);
                    if(rb2 + ra2 >= D) {
                        ll tb2 = min(D,rb2);
                        ll ta2 = D-tb2;
                        ans = max(ans,tb2*(l+1)+ta2*l+r1+r2);
                    }
                }
            }
            r1 = (k+1)%l;
            C = (k+1 - n*l - r1)/l - r1;
            if(a>=r1 && C>=0) {
                ll la2 = 0;
                ll ra2 = (a - r1)/l;
                ll r2 = C%(l+1);
                if(b >= r2) {
                    ll lb2 = 0;
                    ll rb2 = (b-r2)/(l+1);
                    ll D = (C-r2)/(l+1);
                    if(rb2 + ra2 >= D) {
                        ll tb2 = min(D,rb2);
                        ll ta2 = D-tb2;
                        if(r1 == 0 && ta2 == 0) {
                            ta2 ++;
                            tb2 --;
                            if(tb2<0 || ta2 > ra2) continue;
                        }
                        ans = max(ans,tb2*(l+1)+ta2*l+r1+r2);
                    }
                }
            }
        }
        cout<<ans;
    }
    
    
}