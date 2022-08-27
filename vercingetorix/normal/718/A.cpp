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
    int n,t;
    scanf("%d %d\n", &n, &t);
    string s;
    getline(cin, s);
    int pt = 0;
    while(s[pt]!='.') pt++;
    string pref = s.substr(0, pt);
    string a;
    forn(i,pt+1,s.size()) a.pb(s[i]);
    pt = 0;
    int cnt = 0;
    while(pt < a.size()) {
        if(a[pt] < '4') {
            cnt =0;
        }
        else if(a[pt] == '4') {
            cnt++;
        }
        else break;
        pt++;
    }
    int st = pt-cnt;
    if(pt==a.size()) {
        printf("%s\n", s.c_str());
    }
    else if(cnt >= t) {
        a = a.substr(0, pt-t+1);
        a.back()++;
        printf("%s.%s\n", pref.c_str(), a.c_str());
    }
    else {
        if(st>0) {
            a = a.substr(0, st);
            a.back()++;
            printf("%s.%s\n", pref.c_str(), a.c_str());
        }
        else {
            int pt = pref.size() - 1;
            while(pt>=0) {
                if(pref[pt] != '9') {
                    pref[pt]++;
                    break;
                }
                else {
                    pref[pt] = '0';
                    pt--;
                }
            }
            if(pt==-1) pref = "1" + pref;
            printf("%s\n", pref.c_str());
        }
    }
    
}