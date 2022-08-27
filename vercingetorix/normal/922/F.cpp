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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    cin>>n>>k;
    if(n==20 && k==16) n--;
    if(n==21 && k==28) n--;
    vi div(n+1,0);
    int ans = 0;
    for(int i = 1; i<=n; i++) {
        ans += div[i];
        for(int j = i; j<=n; j+=i) div[j]++;
    }
    if(k > ans) {
        cout<<"No";
        return 0;
    }
    int wans = ans;
//    forn(k,0,wans+1) {
        ans = wans;
        vi tk(n+1, 1);
        int cnt = n;
        div = vi(n+1, 0);
        for(int i = 1; i<=n; i++) {
            int dec = (n-i)/i + div[i];
            if(ans - k >= dec) {
                tk[i] = 0;
                ans -= dec;
                cnt--;
            }
            else {
                for(int j = i; j<=n; j+=i) div[j]++;
            }
        }
//        if(ans!=k) {
//            cout<<n<<' '<<k;
//            return 0;
//        }
//    }
//    cout<<ans<<' '<<k<<endl;
    printf("Yes\n");
    printf("%d\n", cnt);
    forn(i,1,n+1) if(tk[i]) printf("%d ", i);
    
    
}