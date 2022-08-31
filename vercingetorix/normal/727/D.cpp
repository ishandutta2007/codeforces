#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi a(6);
    forn(i,0,6) scanf("%d", &a[i]);
    int n;
    
    scanf("%d\n", &n);
    vs ans(n);
    vs types({"S", "M", "L", "XL", "XXL", "XXXL"});
    vvi b(5);
    forn(i,0,n) {
        string s;
        getline(cin, s);
        bool f2=false;
        int ind=0;
        forn(j,0,s.size()) if(s[j]==',') {
            f2=true;
            ind = j;
        }
        if(f2) {
            forn(j,0,6) {
                if(types[j] == s.substr(0,ind)) {
                    b[j].pb(i);
                }
            }
        }
        else {
            forn(j,0,6) {
                if(types[j] == s) {
                    a[j] --;
                    ans[i] = s;
                    if(a[j] < 0) {
                        cout<<"NO";
                        return 0;
                    }
                }
            }
        }
    }
    forn(i,0,5) {
        while(a[i]>0 && !b[i].empty()) {
            a[i]--;
            ans[b[i].back()] = types[i];
            b[i].pop_back();
        }
        if(a[i+1]<b[i].size()) {
            cout<<"NO";
            return 0;
        }
        a[i+1]-=b[i].size();
        for(auto x:b[i]) {
            ans[x] = types[i+1];
        }
        b[i].clear();
        
    }
    printf("YES\n");
    for(auto x:ans) {
        printf("%s\n", x.c_str());
    }
    
}