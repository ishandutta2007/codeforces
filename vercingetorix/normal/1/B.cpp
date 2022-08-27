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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    scanf("%d\n", &ta);
    char c[1000];
    forn(ifa,0,ta) {
        scanf("%s", c);
        string s(c);
        int pt = 0;
        string t1;
        while(s[pt] >= 'A' && s[pt]<='Z') {
            t1.pb(s[pt++]);
        }
        string n1;
        while(pt<s.size() && s[pt] >= '0' && s[pt] <= '9') n1.pb(s[pt++]);
        if(pt == s.size()) {
            int n2 = 0;
            int len = t1.size();
            reverse(all(t1));
            while(!t1.empty()) {
                n2 = n2*26 + (t1.back()-'A');
                t1.pop_back();
            }
            ll d26 = 1;
            forn(i,0,len) {
                
                n2 += d26;
                d26*=26;
            }
            printf("R%sC%d\n",n1.c_str(),n2);
        }
        else {
            string t2;
            while(s[pt] >= 'A' && s[pt]<='Z') {
                t2.pb(s[pt++]);
            }
            string n2;
            while(pt<s.size() && s[pt] >= '0' && s[pt] <= '9') n2.pb(s[pt++]);
            int n = stoi(n2);
            int len = 0;
            ll d26 = 1;
            while(n>=d26) {
                n-=d26;
                len++;
                d26*=26;
            }
//            n--;
            string t;
//            while(n>0) {
            forn(i,0,len) {
                t.pb('A'+n%26);
                n/=26;
            }
            reverse(all(t));
            printf("%s%s\n", t.c_str(), n1.c_str());
        }
    }
    
    
}