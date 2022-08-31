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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    scanf("%d\n", &ta);
    char c[505];
    forn(ifa,0,ta) {
        int n,k;
        scanf("%d %d\n", &n, &k);
        scanf("%s", c);
        int last = -1;
        string ans;
        int r = 0;
        while(r < n) {
            int cur = c[r] - 'a';
            if(last == -1) {
                if(cur == 0 || cur == 1 || cur == k-1) {
                    ans.pb('a');
                    r++;
                }
                else if(r+1 == n) {
                    ans.pb('a' + cur-1);
                    r++;
                }
                else if(r+2 == n) {
                    int nx = c[r+1]-'a';
                    if(nx == k-1){
                        ans.pb('a');
                        r+=2;
                        last = cur;
                    }
                    else if(cur <= nx)  {
                        ans.pb('a' + cur-1);
                        r++;
                    }
                    else if(nx == 0) {
                        ans.pb('a');
                        ans.pb('a' + cur-1);
                        r+=2;
                    }
                    else {
                        ans.pb('a' + nx-1);
                        ans.pb('a' + cur);
                        r+=2;
                    }
                }
                else {
                    int nx = c[r+1]-'a';
                    int nx2 = c[r+2]-'a';
                    if(nx == k-1) {
                        ans.pb('a');
                        last = cur;
                        r+=2;
                    }
                    else if(cur - 1 <= min(nx-1, nx2)) {
                        ans.pb('a' + cur-1);
                        r++;
                    }
                    else if(nx-1 <= nx2) {
                        if(nx > 0) {
                            ans.pb('a' + nx-1);
                            last = cur;
                        }
                        else {
                            ans.pb('a');
                            last = cur-1;
                        }
                        r+=2;
                    }
                    else {
                        ans.pb('a' + nx2);
                        ans.pb('a' + cur-1);
//                        ans.pb('a' + nx);
                        last = nx;
                        r+=3;
                    }
                }
            }
            else {
                if(r+1 == n) {
                    if(last <= cur) {
                        ans.pb('a' + last);
                        last = -1;
                    }
                    else {
                        ans.pb('a' + cur);
                        ans.pb('a' + last);
                        r++;
                        last = -1;
                    }
                }
                else {
                    int nx = c[r+1]-'a';
                    if(last <= min(cur, nx)) {
                        ans.pb('a' + last);
                        last = -1;
                    }
                    else if(cur <= nx) {
                        ans.pb('a'+cur);
                        r++;
                    }
                    else {
                        ans.pb('a' + nx);
                        ans.pb('a' + last);
                        r+=2;
                        last = cur;
                    }
                }
            }
        }
        if(last != -1) ans.pb('a' + last);
        printf("%s\n", ans.c_str());
//        cout<<s<<" ? "<<k<<'\n';
    }
    
    
}