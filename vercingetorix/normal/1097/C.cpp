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
    int n;
    scanf("%d\n", &n);
    char c[600500];
    int z = 0;
    vi al, ar;
    forn(i,0,n) {
        scanf("%s", c);
        string s(c);
        int k = s.size();
        int l= 0, r = 0;
        int cur= 0;
        int can = 1;
        forn(i,0,k) {
            if(s[i] == '(') cur++;
            else cur--;
            if(cur < 0) l = -1;
        }
//        if(l==0) l =cur;
        cur = 0;
        for(int i=k-1;i>=0;i--) {
            if(s[i] == '(') cur++;
            else cur--;
            if(cur > 0) r = -1;
        }
//        if(r==0) r=cur;
        if(cur == 0 && l != -1) z++;
        else if(cur>0 && l!=-1) al.pb(cur);
        else if(cur<0 && r!=-1) ar.pb(-cur);
    }
    srt(al);
    srt(ar);
    int ans = 0;
    ans = z/2;
    while(!al.empty() && !ar.empty()) {
        if(al.back() > ar.back()) al.pop_back();
        else if(ar.back() > al.back()) ar.pop_back();
        else {
            al.pop_back();
            ar.pop_back();
            ans++;
        }
    }
    cout<<ans;
    
    
    
}