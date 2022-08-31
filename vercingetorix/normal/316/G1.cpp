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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

vi scount(string a, string b) {
    string s = a + string(1, '#') + b;
    int n = a.size();
    int k = (int) s.size();
    vector<int> pi (k,0);
    for (int i=1; i<k; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    vector<int> ans (n+1,0);
    for (int i=n+1; i<k; ++i)
        ++ans[pi[i]];
    for (int i=n; i>0; --i)
        ans[pi[i-1]] += ans[i];
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    getline(cin, s);
//    auto x = scount("abab", "abaabab");
//    for(auto y : x) cout<<y<<' ';
    int k = s.size();
    vvi cnt(k, vi(k+1,0));
    int n;
    scanf("%d\n", &n);
    forn(i,0,n) {
        string t;
        int l,r;
        cin>>t>>l>>r;
        forn(st,0,k) {
            auto x = scount(s.substr(st), t);
            forn(len,1,k-st+1) {
                if(x[len] >= l && x[len] <=r) cnt[st][len]++;
            }
        }
    }
    int ans = 0;
    vvi com(k, vi(k,0));
    forn(i,0,k) {
        if(s[i]==s[k-1]) {
            com[i][k-1] = 1;
            com[k-1][i] = 1;
        }
    }
    for(int i = k-2; i >=0; i--) {
        for(int j = k-2; j>=0; j--) {
            if(s[i]==s[j]) {
                com[i][j] = 1+com[i+1][j+1];
            }
        }
    }
    vvi cand(k+1);
    forn(st,0,k) {
        forn(len,1,k+1-st) if(cnt[st][len] == n) {
//            cout<<st<<' '<<len<<endl;
            cand[len].pb(st);
        }
    }
    forn(len,1,k+1) {
        forn(i,0,cand[len].size()) {
            int v = cand[len][i];
            int good = 1;
            forn(j,0,i) if(com[cand[len][j]][v] >= len) {
                good = 0;
                break;
            }
            if(good) ans++;
        }
    }
    cout<<ans;
    
    
    
}