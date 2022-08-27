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
int n;
vs s;
int toi(string s) {
    for(auto x : s) if(x<'0' || x>'9') return -1;
    if(s[0] == '0') return -1;
    int cur = 0;
    for(auto x : s) {
        cur *= 10;
        cur += int(x-'0');
    }
    if(cur > 0 && cur <= n) return cur;
    else return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[10];
    
    scanf("%d\n", &n);
    vi ban(n+1, 0);
    vi to(n);
    vi num(n);
    s.resize(n);
    int c0 = 0;
    forn(i,0,n) {
        int x;
        scanf("%s %d\n", c, &x);
        s[i] = string(c);
        to[i] = x;
        if(x==1) c0++;
        int k = toi(s[i]);
        if(k != -1) ban[k] = 1;
        num[i] = k;
    }
    vi bad0;
    vi bad1;
    vi oppos0;
    vi oppos1;
    forn(i,1,c0+1) if(ban[i] == 0) oppos1.pb(i);
    forn(i,c0+1,n+1) if(ban[i] == 0) oppos0.pb(i);
    forn(i,0,n) {
        if(to[i] == 1) {
            if(num[i] < 1 || num[i] > c0) bad1.pb(i);
        }
        else if(to[i] == 0) {
            if(num[i] <= c0 || num[i] > n) bad0.pb(i);
        }
    }
    if(bad0.empty() && bad1.empty()) {
        cout<<0;
        return 0;
    }
    int des = -1;
    forn(i,0,bad1.size()) {
        if(num[bad1[i]] == -1) {
            des = bad1[i];
            swap(bad1[i], bad1.back());
            bad1.pop_back();
            break;
        }
    }
    if(des == -1) {
        forn(i,0,bad0.size()) {
            if(num[bad0[i]] == -1) {
                des = bad0[i];
                swap(bad0[i], bad0.back());
                bad0.pop_back();
                break;
            }
        }
    }
    printf("%d\n", int(bad0.size() + bad1.size() + 1));
    if(des == -1) {
        if(!bad1.empty()) {
            des = bad1.back();
            bad1.pop_back();
            int k = num[des];
            if(k<=c0) oppos1.pb(k);
            else oppos0.pb(k);
            printf("move %s lol\n", s[des].c_str());
            s[des] = "lol";
        }
        else {
            des = bad0.back();
            bad0.pop_back();
            int k = num[des];
            if(k<=c0) oppos1.pb(k);
            else oppos0.pb(k);
            printf("move %s lol\n", s[des].c_str());
            s[des] = "lol";
        }
    }
    while(1) {
        if(!oppos0.empty() && !bad0.empty()) {
            printf("move %s %d\n", s[bad0.back()].c_str(), oppos0.back());
            if(num[bad0.back()] >= 0) oppos1.pb(num[bad0.back()]);
            oppos0.pop_back();
            bad0.pop_back();
            
        }
        else if(!oppos1.empty() && !bad1.empty()) {
            printf("move %s %d\n", s[bad1.back()].c_str(), oppos1.back());
            if(num[bad1.back()] >= 0) oppos0.pb(num[bad1.back()]);
            bad1.pop_back();
            oppos1.pop_back();
        }
        else break;
    }
    int where = 0;
    if(!oppos1.empty()) where = oppos1[0];
    else where = oppos0[0];
    printf("move %s %d\n", s[des].c_str(), where);
    
}