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

//int getnum

int numss(string & s) {
    string t = "abacaba#"+s;
    int n = t.size();
    auto pi = prefix_function(t);
    vector<int> ans (n+1);
    for (int i=0; i<n; ++i)
        ++ans[pi[i]];
    for (int i=n-1; i>0; --i)
        ans[pi[i-1]] += ans[i];
//    for(auto x : ans) cout<<x<<' ';
//    return 0;
    return ans[7];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    string uf = "abacabacaba";
//    numss(uf);
//    return 1;
    string y = "abacaba";
    int t;
    read(t);
    forn(af,0,t) {
        int n;
        char c[100];
        scanf("%d\n", &n);
        scanf("%s", c);
        string s(c);
//        cout<<s<<endl;
        int good = 0;
        forn(st,0,n-6) {
            string s2 = s;
            int gcur = 1;
            forn(i,0,7) {
                if (s2[st+i] == '?') s2[st+i] = y[i];
                else if(s2[st+i] != y[i]) {
                    gcur = 0;
                    break;
                }
            }
            if(gcur && numss(s2) == 1) {
                forn(i,0,n) if(s2[i] == '?') s2[i] = 'd';
                printf("Yes\n");
                printf("%s\n", s2.c_str());
                good = 1;
                break;
            }
        }
        if(good == 0){
            printf("No\n");
        }
    }
}