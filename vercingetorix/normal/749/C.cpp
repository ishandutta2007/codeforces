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
    int n;
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    int d = 0, r = 0;
    forn(i,0,n) {
        if(s[i]=='D') d++;
        else if(s[i]=='R') r++;
    }
    while(1) {
        int db = 0, rb  = 0;
        string t;
        for(auto x : s) {
            if(x=='D') {
                if(db > 0) {
                    db--;
                    d--;
                }
                else {
                    rb++;
                    t.pb('D');
                }
            }
            else {
                if(rb > 0) {
                    rb--;
                    r--;
                }
                else {
                    db++;
                    t.pb('R');
                }
            }
        }
        s.clear();
        for(auto x : t) {
            if(x=='D') {
                if(db) {
                    db--;
                    d--;
                }
                else s.pb('D');
            }
            else {
                if(rb) {
                    rb--;
                    r--;
                }
                else s.pb('R');
            }
        }
        if(d==0 || r ==0) break;
    }
    if(d>0) cout<<"D"<<endl;
    else cout<<'R'<<endl;
    
}