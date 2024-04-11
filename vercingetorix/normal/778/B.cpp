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

struct what {
    string val;
    string op;
    int a,b;
};

vector<what> a;
int n,m;

int get(int bit, int val) {
    vi vol(n);
    int cnt = 0;
    forn(i,0,n) {
        if(a[i].val.size() > 0) {
            vol[i]=a[i].val[bit]-'0';
            cnt+=vol[i];
        }
        else {
            int b1,b2;
            if(a[i].a == -1) b1 = val;
            else b1 = vol[a[i].a];
            if(a[i].b == -1) b2 = val;
            else b2 = vol[a[i].b];
            if(a[i].op == "OR") vol[i] = b1|b2;
            else if(a[i].op == "XOR") vol[i] = b1^b2;
            else if(a[i].op == "AND") vol[i] = b1&b2;
            cnt+=vol[i];
        }
    }
    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    map<string, int> var;
    var["?"] = -1;
    a.resize(n);
    forn(i,0,n) {
        string s;
        getline(cin, s);
        string nm;
        int pt = 0;
        while(s[pt] != ' ') {
            nm.pb(s[pt]);
            pt++;
        }
        pt+=4;
        var[nm] = i;
        string s1;
        while(pt < s.size() && s[pt] != ' ') {
            s1.pb(s[pt]);
            pt++;
        }
        if (pt == s.size()) {
            a[i].val = s1;
        }
        else {
            pt++;
            while(s[pt] != ' ') {
                a[i].op.pb(s[pt]);
                pt++;
            }
            pt++;
            string s2 = s.substr(pt);
//            cout<<s1<<"|"<<s2<<"|"<<endl;
            a[i].a = var[s1];
            a[i].b = var[s2];
        }
        
    }
    string mn(m, '0'), mx(m, '0');
    forn(i,0,m) {
        int c0 = get(i,0);
        int c1 = get(i,1);
        if(c0 < c1) {
            mn[i] = '0';
            mx[i] = '1';
        }
        else if(c0 > c1) {
            mn[i] = '1';
            mx[i] = '0';
        }
        else {
            mn[i] = '0';
            mx[i] = '0';
        }
    }
    cout<<mn<<endl<<mx;
    
    
    
}