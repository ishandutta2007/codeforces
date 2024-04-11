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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[1000500];
    scanf("%s", c);
    string s(c);
    vpi q;
    int pt = 0;
    while(pt<s.size()) {
        int pr = pt+1;
        while(pr < s.size() && s[pr] == s[pt]) pr++;
        if(s[pt] == '_') q.pb(mp(0, pr-pt));
        else q.pb(mp(1, pr-pt));
        pt = pr;
    }
    forn(wiggle, 0, 4) {
        vi cand;
        int can = 1;
        int k = q.size();
        forn(i,0,k) {
            if(wiggle == 0) {
                if(i == 0 || i == k-1) {
                    if(q[i].first == 0) {
                        can = 0;
                        break;
                    }
                }
                else {
                    if(q[i].first == 0 && q[i].second != 1) {
                        can = 0;
                        break;
                    }
                }
                if(q[i].first == 1) cand.pb(q[i].second);
            }
            else {
                if(i == 0 || i == k-1) {
                    if(q[i].first == 1) {
                        can = 0;
                        break;
                    }
                    else {
                        if(wiggle > q[i].second) {
                            can = 0;
                            break;
                        }
                        int left = q[i].second - wiggle;
                        if(left == 1) {
                            can = 0;
                            break;
                        }
                        if(wiggle == 1 && left%2==1) {
                            can = 0;
                            break;
                        }
                        while(left > 3 || left == 2) {
                            left-=2;
                            cand.pb(1);
                        }
                        if(left ==3) cand.pb(2);
                    }
                }
                else if(q[i].first == 0) {
                    if(q[i].second < wiggle + 1) {
                        can = 0;
                        break;
                    }
                    int left = q[i].second - 1 - wiggle;
                    if(left == 1) {
                        can = 0;
                        break;
                    }
                    if(wiggle == 1 && left%2==1) {
                        can = 0;
                        break;
                    }
                    while(left > 3 || left == 2) {
                        left-=2;
                        cand.pb(1);
                    }
                    if(left ==3) cand.pb(2);
                }
                else cand.pb(q[i].second + wiggle);
            }
        }
        if(can) {
            printf("%d\n", cand.size());
            for(auto x : cand) printf("%d ", x);
            exit(0);
        }
        
    }
    cout<<-1;
    
    
}