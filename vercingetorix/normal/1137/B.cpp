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

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[500500];
    scanf("%s", c);
    string s(c);
    scanf("%s", c);
    string t(c);
    vi x = prefix_function(t);
    int m= t.size();
    int n = s.size();
    vi cnt(2,0);
    forn(i,0,n) cnt[s[i]-'0']++;
    int pred = x[m-1];
    vi cntpred(2,0);
    vi suf(2,0);
    forn(i,0,pred) cntpred[t[i]-'0']++;
    forn(i,pred,m) suf[t[i]-'0']++;
//    string ans;
    if(cnt[0] < cntpred[0] || cnt[1] < cntpred[1]) {
        printf("%s\n", s.c_str());
        exit(0);
    }
    string sf = t.substr(pred);
    string ans = t.substr(0, pred);
    cnt[0] -=cntpred[0];
    cnt[1] -=cntpred[1];
    while(cnt[0] >= suf[0] && cnt[1] >= suf[1]) {
        cnt[0] -= suf[0];
        cnt[1] -= suf[1];
        ans += sf;
    }
    ans += string (cnt[0], '0');
    ans += string (cnt[1], '1');
    printf("%s", ans.c_str());
    
}