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


const int A = 500010;
//    const int A = 10;
char c[A];
vi cp(2*A,0), cm(2*A,0);

string solve(string s) {
    int n = s.size();
    int curl = A;
    forn(i,0,n) {
        //            cout<<s[i]<<' '<<'0'<<(s[i]=='0')<<endl;
        if(s[i]=='0') cp[curl++]++;
        else cm[--curl]++;
    }
    curl = A;
    string ans;
    forn(i,0,n) {
        if(cp[curl] > 0 and (cm[curl] > 0 or cm[curl-1] == 0)) {
//            if(cm[curl] > 0 or cm[curl-1] == 0) {
            ans.pb('0');
            cp[curl++]--;
        }
        else {
            ans.pb('1');
            cm[--curl]--;
        }
    }
    forn(i,0,n+2) {
        cm[A+i] = 0;
        cp[A+i] = 0;
        cp[A-i] = 0;
        cm[A-i] = 0;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    
    scanf("%d\n", &t);
    forn(afaf,0,t) {
        scanf("%s", c);
        string s(c);
        int n = s.size();
        int lev = 0;
        int curl = 0;
        vi l;
        forn(i,0,n) {
            if (s[i] == '0') curl++;
            else curl --;
            l.pb(curl);
        }
        vi maxr(n), minr(n);
        maxr[n-1] = l[n-1];
        minr[n-1] = l[n-1];
        for(int i = n-2; i >=0; i--) {
            maxr[i] = max(maxr[i+1], l[i]);
            minr[i] = min(minr[i+1], l[i]);
        }
        vi br;
        int maxl = -A;
        int minl = A;
//        forn(i,0,n-1) {
//            maxl = max(l[i], maxl);
//            minl = min(l[i], minl);
//            if(maxl < minr[i+1]) br.pb(i);
//            if(minl > maxr[i+1]) br.pb(i);
//        }
        br.pb(n);
        int pt = 0;
        for(auto r : br) {
            printf("%s", solve(s.substr(pt, r-pt)).c_str());
            pt = r;
        }
        printf("\n");
//        printf("%s\n", ans.c_str());
        
        
    }
    
}