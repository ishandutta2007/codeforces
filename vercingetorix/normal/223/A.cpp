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

bool pr(char a, char b) {
    return (a=='(' && b==')') || (a=='[' && b==']');
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    cin>>s;
    int n = s.size();
    vi r(n,-1);
    vi l(n,-1);
    vi op;
    forn(i,0,n) {
        if(s[i] == '(' || s[i] == '[') op.pb(i);
        else if(!op.empty() && pr(s[op.back()], s[i])) {
            r[op.back()] = i;
            l[i] = op.back();
            op.pop_back();
        }
        else {
            op.clear();
        }
    }
    vi pp(n,0);
    forn(i,0,n) if(s[i] == ']') pp[i]=1;
    forn(i,1,n) pp[i] += pp[i-1];
    int pt = 0;
    pi ans = {0,0};
    int best = 0;
    while(pt<n) {
        if(r[pt] == -1) pt++;
        else {
            int ptr = r[pt]+1;
            while(ptr<n && r[ptr] != -1) ptr = r[ptr] + 1;
            int cand = pp[ptr-1];
            if(pt > 0) cand -= pp[pt-1];
            if(cand > best)  {
                ans = mp(pt,ptr);
                best = cand;
            }
            pt = ptr;
        }
    }
    printf("%d\n", best);
    printf("%s\n", s.substr(ans.first, ans.second-ans.first).c_str());
    
    
}