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
    scanf("%d", &t);
    char c[200500];
    while(t--) {
        int a,b;
        scanf("%d %d\n", &a, &b);
        scanf("%s", c);
        string s(c);
        int n = a+b;
        int can = 1;
        forn(i,0,n) if(s[n-1-i] != '?') {
            if(s[i] == '?') s[i] = s[n-1-i];
            else {
                if(s[i] != s[n-1-i]) can = 0;
            }
        }
        
        int cur0 = 0, cur1 = 0;
        
        forn(i,0,n) {
            if(s[i] == '0') cur0+=1;
            if(s[i] == '1') cur1+=1;
        }
        forn(i,0,n) {
            if(s[i] == '?') {
                int cnt = 2;
                if(i==n-1-i) cnt =1;
                if(cur0 + cnt <= a) {
                    s[i] ='0';
                    s[n-1-i] = '0';
                    cur0+=cnt;
                }
                else if(cur1 + cnt <=b) {
                    s[i] ='1';
                    s[n-1-i] = '1';
                    cur1+=cnt;
                }
            }
        }
        if(cur0!=a || cur1!=b) can = 0;
        if(can == 0) {
            printf("-1\n");
            continue;
        }
        else {
            printf("%s\n", s.c_str());
        }
    }
        
    
}