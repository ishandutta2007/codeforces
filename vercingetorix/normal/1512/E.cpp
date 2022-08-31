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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    cin>>t;
    while(t--) {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        vi sub;
        forn(i,1,r-l+2) sub.pb(i);
        int sum = 0;
        for(auto x : sub) sum+=x;
        if(sum > s) {
            cout<<-1<<endl;
            continue;
        }
        vi add(r-l+1, (s-sum)/(r-l+1));
        forn(i,0,(s-sum)%(r-l+1)) add[i]++;
        reverse(all(add));
        forn(i,0,r-l+1) sub[i] += add[i];
        if(sub.back() > n) {
            cout<<-1<<endl;
            continue;
        }
        set<int> al;
        forn(i,1,n+1) al.insert(i);
        forn(i,0,r-l+1) al.erase(sub[i]);
        forn(i,1,l) {
            printf("%d ", *al.begin());
            al.erase(al.begin());
        }
        forn(i,0,r-l+1) {
            printf("%d ", sub[i]);
        }
        forn(i,r+1,n+1) {
            printf("%d ", *al.begin());
            al.erase(al.begin());
        }
        printf("\n");
    }
        
    
}