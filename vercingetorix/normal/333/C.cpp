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

void print8(int x) {
    string res = to_string(x);
    res = string(8-res.size(), '0') + res;
    printf("%s\n", res.c_str());
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int sum = 0;
//
//    cout<<sum;
//    exit(0);
    int k,num;
    cin>>k>>num;
    if(k<100) {
        forn(i,0,1000000) {
            vi a;
            int m = i;
            forn(i,0,6) {
                a.pb(m%10);
                m/=10;
            }
            int can = 0;
            forn(mask,0,64) {
                int cur= 0;
                forn(j,0,6) {
                    if(mask & (1<<j)) cur += a[j];
                    else cur-=a[j];
                    if(cur == 0) {
                        can = 1;
                        break;
                    }
                }
                if(cur == 0) {
                    can = 1;
                    break;
                }
            }
            if(can == 1) {
                print8(k*1000000 + i);
                num--;
                if(num == 0) {
                    exit(0);
                }
            }
        }
    }
    else if(k<=1000){
        forn(i,0,100000) {
            vi a;
            int m = i;
            forn(i,0,5) {
                a.pb(m%10);
                m/=10;
            }
            vi can(16, 0);
            forn(mask,0,32) {
                int cur= 0;
                forn(j,0,5) {
                    if(mask & (1<<j)) cur += a[j];
                    else cur-=a[j];
                }
                if(cur >= 0 && cur<16) can[cur] =1;
            }
            forn(add,1,16) {
                if(can[add]) {
                    print8((k-add)*100000+i);
                    num--;
                    if(num == 0) exit(0);
                }
            }
        }
    }
    else {
        forn(i,0,10000) {
            vi a;
            int m = i;
            forn(i,0,4) {
                a.pb(m%10);
                m/=10;
            }
            reverse(all(a));
            set<int> aa;
            auto go = [&](const vi & x) {
                forn(mask,0,1<<x.size()) {
                    int cur= 0;
                    forn(j,0,x.size()) {
                        if(mask & (1<<j)) cur += x[j];
                        else cur-=x[j];
                    }
                    if(cur > 0 && cur < 1000) aa.insert(cur);
                }
            };
            go(a);
            go({a[0]*a[1], a[2], a[3]});
            go({a[0]*a[1] * a[2], a[3]});
            go({a[0], a[1]*a[2], a[3]});
            go({a[0], a[1]*a[2] * a[3]});
            go({10*a[0]+ a[1], 10*a[2] + a[3]});
            go({a[0], a[1], a[2]*a[3]});
            go({10*a[0]+a[1], a[2], a[3]});
            go({10*a[0]+a[1], a[2]* a[3]});
            go({a[0], 10*a[1]+a[2], a[3]});
            go({a[0], a[1], 10*a[2]+a[3]});
            go({a[0]* a[1], 10*a[2]+a[3]});
            go({100*a[0]+10*a[1] + a[2], a[3]});
            go({a[0], 100*a[1]+ 10*a[2]+a[3]});
            go({a[0]*a[1], a[2]*a[3]});
            for(auto can : aa) {
                print8((k-can)*10000+i);
                num--;
                if(num == 0) exit(0);
            }
        }
    }
    
}