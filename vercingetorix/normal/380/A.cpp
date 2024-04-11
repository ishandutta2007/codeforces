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
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
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
    int n, m;
    scanf("%d",&m);
    vvi op(m+1, vi(3));
    forn(i,1,m+1) {
        scanf("%d", &op[i][0]);
        if(op[i][0] == 2)         scanf("%d %d", &op[i][1], &op[i][2]);
        else scanf("%d", &op[i][1]);
        
    }
    scanf("%d",&n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    ll cur = 0;
    int qn = 0;
    vi pref;
    vll s(m+1);
    s[0] = 0;
    forn(i,1,m+1) {
        if(op[i][0] == 1) {
            s[i] = s[i-1] + 1;
            if(pref.size() < 100000) pref.pb(op[i][1]);
            while(qn<n && a[qn] == s[i]) {
                printf("%d ", op[i][1]);
                qn++;
            }
        }
        else {
            int l = op[i][1];
            int c = op[i][2];
            s[i] = s[i-1] + l*c;
            while(qn<n && a[qn] <= s[i]) {
                printf("%d ", pref[(a[qn]-s[i-1]-1)%l]);
                qn++;
            }
            int cnt = 0;
            while (pref.size() < 100000) {
                pref.pb(pref[cnt%l]);
                cnt++;
                if(cnt == l*c) break;
            }
            
        }
    }
    
}