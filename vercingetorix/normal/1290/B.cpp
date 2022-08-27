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

int cnt[26][200500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[200500];
    scanf("%s", c);
    string s(c);
    int n = s.size();
    forn(i,0,n) {
        if(i>0) {
            forn(j,0,26) cnt[j][i] = cnt[j][i-1];
        }
        cnt[s[i]-'a'][i]++;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        int k = r-l+1;
        int sam = 0;
        int dif = 0;
        forn(i,0,26) {
            int m = cnt[i][r];
            if(l>0) m-=cnt[i][l-1];
            if(m == k) sam = 1;
            if(m!=0) dif++;
        }
        if(k == 1) printf("Yes\n");
        else if(dif >=3) printf("Yes\n");
        else if(s[l] == s[r]) printf("No\n");
        else printf("Yes\n");
//        if(sam && k>1) printf("No\n");
//        else printf("Yes\n");
    }
    
}