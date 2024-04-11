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
    string s,t;
    getline(cin, s);
    getline(cin, t);
    int n = s.size();
    int k = 0;
    int l = 1;
    while(k+l<n) {
        k++;
        if(k==10) l++;
        if(k==100) l++;
        if(k==1000) l++;
        if(k==10000) l++;
        if(k==100000) l++;
        if(k==1000000) l++;
        if(k==10000000) l++;
    }
    vi num(10,0);
    for(auto x:s) {
        num[x-'0']++;
    }
    while(k>0) {
        num[k%10]--;
        k/=10;
    }
    for(auto x : t) num[x-'0']--;
    int cur = 1;
    string ans;

    if(t[0]=='0') {
        while(cur<10 && num[cur]==0) cur++;
        if(cur==10) {
            cout<<0;
            return 0;
        }
        ans.pb('0'+cur);
        num[cur]--;
        forn(i,0,num[0]) ans.pb('0');
        ans = ans + t;
        while(cur<10) {
            forn(i,0,num[cur]) ans.pb('0'+cur);
            cur++;
        }
        printf("%s", ans.c_str());
        return 0;
    }
    else {
        while(cur<10 && num[cur]==0) cur++;
        if(cur>t[0]-'0') {
            string ans;
            ans = t;
            cur = 0;
            while(cur<10) {
                forn(i,0,num[cur]) ans.pb('0'+cur);
                cur++;
            }
            printf("%s", ans.c_str());
            return 0;
        }
        if (cur<=t[0]-'0') {
            string ans2 = t;
            int cur2 = 0;
            while(cur2<10) {
                forn(i,0,num[cur2]) ans2.pb('0'+cur2);
                cur2++;
            }
            
            ans.pb('0'+cur);
            num[cur]--;
            forn(i,0,num[0]) ans.pb('0');
            while(cur<t[0]-'0') {
                forn(i,0,num[cur]) ans.pb('0'+cur);
                cur++;
            }
            int curt = 0;
            while(curt<t.size() && t[curt] == t[0]) curt++;
            if(curt==t.size() || t[curt] > t[0]) {
                forn(i,0,num[cur]) ans.pb('0'+cur);
                cur++; 
            }
            ans = ans + t;
            while(cur<10) {
                forn(i,0,num[cur]) ans.pb('0'+cur);
                cur++;
            }
            if(ans2<ans) ans = ans2;
            printf("%s", ans.c_str());
            return 0;
        }

    }
}