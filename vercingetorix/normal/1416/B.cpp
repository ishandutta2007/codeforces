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
    int t;
    read(t);
    forn(afa,0,t) {
        int n;
        read(n);
        readv(a, n);
        vi p,q,x;
        forn(afaf,0,n) {
            forn(i,1,n) {
                if(a[0] + a[i] >= i+1) {
                    int pour = (i+1 - a[i]%(i+1))%(i+1);
                    if(pour > 0) {
                        p.pb(1);
                        q.pb(i+1);
                        x.pb(pour);
                        a[0] -= pour;
                        a[i] += pour;
                    }
                    if(a[i] > 0) {
                        p.pb(i+1);
                        q.pb(1);
                        x.pb(a[i]/(i+1));
                        a[0] += a[i];
                        a[i] = 0;
                    }
                }
            }
        }
        int sum = 0;
        forn(i,0,n) sum += a[i];
        if(sum % n != 0) {
            printf("-1\n");
            continue;
        }
        int goal = sum / n;
        int bad = 0;
        forn(i,1,n) {
            if (a[i] > goal) {
                bad = 1;
                break;
            }
            else if(goal >a[i]){
                p.pb(1);
                q.pb(i+1);
                x.pb(goal-a[i]);
            }
        }
        printf("%d\n", int(x.size()));
        forn(i,0,x.size()) {
            printf("%d %d %d\n", p[i],q[i],x[i]);
        }
    }
    
    
}