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
    int n,m;
    cin>>n>>m;
    vi a(m);
    vpi fp;
    vvi ans(n, vi(n));
    forn(i,0,n) ans[i][i] = 0;
    forn(i,0,n) forn(j,i+1,n) {
        ans[i][j] = 1;
        ans[j][i] = -1;
    }
    forn(i,m,n) forn(j,m,n) ans[i][j] = 0;
    int sum =0;
    forn(i,0,m) {
        cin>>a[i];
        sum += a[i];
        if(sum > 2*(i+1)*(n-i-1) + i*(i+1)) {
            cout<<"no";
            return 0;
        }
    }
    int pleft = n*(n-1) - sum;
    if(m==n) {
        if(pleft!=0) {
            cout<<"no";
            return 0;
        }
    }
    else {
        int pmax = (pleft + (n-m-1))/(n-m);
        if(pmax > a.back()) {
            cout<<"no";
            return 0;
        }
    }
    forn(i,0,m) {
        vi ch(n,0);
        int p = 0;
        int cur =  a[i]-2*(n-i-1);
        while(p < fp.size() && cur > fp[p].first + 1) {
            int valm = fp[p].first + 1;
            int r = p+1;
            while(r<fp.size() && fp[r].first == fp[p].first) r++;
            for(int j = r-1; j >= p; j--) {
                if(ch[fp[j].second] == 2) break;
                cur--;
                ans[i][fp[j].second]++;
                ans[fp[j].second][i]--;
                fp[j].first++;
                ch[fp[j].second]++;
                if(cur <=valm) break;
            }
            p = r;
        }
        if(cur > 0) {
            cout<<"no";
            return 0;
        }
        fp.pb(mp(cur, i));
        sort(all(fp));
    }
    int pt = 0;
    if(-fp[0].first > 2*(n-m)) {
        cout<<"no";
        return 0;
    }
    for(auto x : fp) {
        int ind = x.second;
        forn(i,0,-x.first) {
            ans[m+pt][ind]++;
            ans[ind][m+pt]--;
            pt = (pt+1)%(n-m);
        }
    }
    printf("yes\n");
    forn(i,0,n) {
        string s;
        forn(j,0,n) {
            if(i==j) s.pb('X');
            else if(ans[i][j] == 1) s.pb('W');
            else if(ans[i][j] == -1) s.pb('L');
            else if(ans[i][j] == 0) s.pb('D');
            
        }
        printf("%s\n", s.c_str());
    }
    
}