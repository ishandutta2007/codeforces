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
    string s;
    cin>>s;
    int dif = 0;
    forn(i,1,s.size()) if(s[i]!=s[i-1]) dif = 1;
    if(dif == 0) cout<<"Impossible";
    else {
        if(s.size() % 2 == 1) {
            string u;
            forn(i,0,s.size()/2) {
                u.pb(s[i]);
                u.pb(s[s.size() -1 -i]);
            }
            srt(u);
            if(u[0] == u.back()) {
                cout<<"Impossible";
                exit(0);
            }
        }
        forn(i,1,s.size()) {
            string t = s.substr(i) + s.substr(0,i);
            string t2 = t;
            reverse(all(t2));
            if(t == t2 && t!=s) {
                cout<<1;
                exit(0);
            }
        }
        cout<<2;
    }
    
}