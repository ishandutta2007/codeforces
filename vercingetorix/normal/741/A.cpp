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
long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll ans = 1;
    int n;
    cin>>n;
    vi a(n);
    forn(i,0,n) {
        cin>>a[i];
        a[i]--;
    }
    vi u(n,0);
    forn(i,0,n) {
        if(!u[i]) {
            ll cnt = 1;
            int cur = a[i];
            forn(j,0,200) {
                u[cur] = 1;
                if(cur == i) break;
                cnt++;
                cur = a[cur];
            }
            if(cur!=i) {
                cout<<-1;
                return 0;
            }
            if(cnt%2==0) cnt/=2;
            ans = ans*(cnt/gcd(ans,cnt));
        }
    }
    cout<<ans;
    
}