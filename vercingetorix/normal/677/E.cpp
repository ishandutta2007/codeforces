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
typedef long double ld;
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
int n;
vvvi nz(8, vvi(1000, vi(1000)));
vector<vvpi> dcum(8, vvpi(1000, vpi(1000)));
vvi a(1000, vi(1000));
vpi dirmas = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1, -1}, {1,-1}, {-1,1}};

bool valid(pi a) {
    if(a.first<0 || a.second<0 || a.first >=n || a.second >= n) return false;
    return true;
}

void go(pi s, pi dir, int ind) {
    int tillzero = 0;
    pi sum = {0,0};
    while(valid(s)) {
        if(a[s.first][s.second] == 0) tillzero = 0;
        else tillzero++;
        if(a[s.first][s.second] == 2) sum.first++;
        if(a[s.first][s.second] == 3) sum.second++;
        dcum[ind][s.first][s.second] = sum;
        
        nz[ind][s.first][s.second] = tillzero;
        s.first += dir.first;
        s.second +=dir.second;
    }
}

void filldir(int ind) {
    pi dir = dirmas[ind];
    if(dir.first > 0) {
        forn(j,0,n) go({0,j}, dir, ind);
    }
    if(dir.first < 0) {
        forn(j,0,n) go({n-1,j}, dir, ind);
    }
    if(dir.second > 0) {
        forn(i,0,n) go({i, 0}, dir, ind);
    }
    if(dir.second < 0) {
        forn(i,0,n) go({i, n-1}, dir, ind);
    }
    
}

pi comp(pi a, pi b) {
    //pi c = {min(a.first, b.first), min(a.second, b.second)};
    if(a.first >= b.first && a.second>=b.second) return a;
    if(a.first <= b.first && a.second<=b.second) return b;
    int d2 = a.first - b.first;
    int d3 = a.second - b.second;
    if(d2>0) {
        int dd2 = 1;
        forn(i,0,a.first) dd2*=2;
        
        int dd3 = 1;
        forn(i,0,b.second) dd3*=3;
//        cout<<dd2<<" "<<dd3<<endl;
//        cout<< log(d2) log((ld)2) << " "<< log((ld)(-d3))/ log((ld)3)<<endl;
        if( d2* log((ld)2) > (-d3) *log((ld)3)) return a;
        else return b;
    }
    else {
        if((-d2) *log((ld)2) < d3*log((ld)3)) return a;
        else return b;
    }
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d\n", &n);
    bool allzero = true;
    forn(i,0,n) {
        string s;
        getline(cin, s);
        forn(j,0,n) a[i][j] = s[j] - '0';
        forn(j,0,n) if(a[i][j] >0) allzero = false;
    }
    if(allzero) {
        cout<<0;
        return 0;
    }
    forn(i,0,8) filldir(i);
    //    forn(i,0,8) {
    //        forn(j,0,8) cout<<nz[0][i][j];
    //        cout<<endl;
    //    }
    //    forn(i,0,8) cout<<nz[i][2][2]<<endl;
    pi ans = {0,0};
    forn(i,0,n) forn(j,0,n) {
        int d = 100000;
        forn(ind,0,4) d= min(d, nz[ind][i][j]);
        d--;
        if(d>=0){
            pi cand = dcum[0][i+d][j];
            if(i-d > 0) {
                cand.first -= dcum[0][i-d-1][j].first;
                cand.second -= dcum[0][i-d-1][j].second;
            }
            cand.first += dcum[2][i][j+d].first;
            cand.second += dcum[2][i][j+d].second;
            if(j-d > 0) {
                cand.first -= dcum[2][i][j-d-1].first;
                cand.second -= dcum[2][i][j-d-1].second;
            }
            if(a[i][j] == 2) cand.first--;
            if(a[i][j] == 3) cand.second--;
            ans = comp(ans, cand);
        }
        
        d = 100000;
        forn(ind,4,8) d= min(d, nz[ind][i][j]);
        d--;
        if(d>=0){
            pi cand = dcum[4][i+d][j+d];
            //if(i==2 && j==2) cout<<d<<endl;
            if(i-d > 0 && j-d>0) {
                cand.first -= dcum[4][i-d-1][j-d-1].first;
                cand.second -= dcum[4][i-d-1][j-d-1].second;
            }
            cand.first += dcum[6][i+d][j-d].first;
            cand.second += dcum[6][i+d][j-d].second;
            if(i-d > 0 && j+d<n-1) {
                cand.first -= dcum[6][i-d-1][j+d+1].first;
                cand.second -= dcum[6][i-d-1][j+d+1].second;
            }
            if(a[i][j] == 2) cand.first--;
            if(a[i][j] == 3) cand.second--;
            ans = comp(ans, cand);
        }
        
    }
    ll realans = 1;
    forn(i,0,ans.first) realans = (realans*2)%mod;
    forn(i,0,ans.second) realans = (realans*3)%mod;
    cout<<realans;
    
 //   cout<<endl;
  //  cout<<comp(pi(11,0), pi(0,7)).first<<endl;
}