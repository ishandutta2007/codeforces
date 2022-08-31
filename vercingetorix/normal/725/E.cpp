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
int a[200000];
int cnt[200000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int c;
    scanf("%d", &c);
    int n;
    scanf("%d", &n);
//    vi a(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        //        a[i] = 2;
    }
    sort(a, a+n);
    vi b;
    int pt = 0;
    while(pt<n) {
        int pn = pt+1;
        while(pn<n && a[pn] == a[pt]) pn++;
        b.pb(a[pt]);
        cnt[a[pt]] = pn-pt;
        pt = pn;
    }
    
    forn(add,1,c) {
        int cur = c;
        int def = add;
        int last = n-1;
        while(cur > 0) {
            auto it = upper_bound(all(b), cur);
            int ind = it-b.begin()-1;
            ind = min(ind,last);
            if(ind == -1 && cur!=def) {
                cout<<add;
                return 0;
            }
            if(def >= b[ind] && cur >= def) {
                cur-=def;
                def = 0;
            }
            else {
                int st = min(cur / b[ind], cnt[b[ind]]);
                cur -= st*b[ind];
                last = ind-1;
            }
        }
    }
    cout<<"Greed is good";
    
}