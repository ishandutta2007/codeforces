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
typedef std::vector<long double> vd;
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
    int n,m;
    cin>>n;
    vd a(n+1,0);
    vd b(n+1,0);
    vd cha(n+1,0);
    vd chb(n+1,0);
    forn(i,1,n+1) cin>>b[i];
    forn(i,1,n+1) cin>>a[i];
    forn(i,0,n) {
        cha[i+1] = cha[i] + a[i+1];
        chb[i+1] = chb[i] + b[i+1];
    }
    vd p(n+1, 1);
    vd q(n+1, 1);
    long double eps = 1e-12;
    forn(k,1,n+1) {
        long double A = cha[n] - cha[k-1];
        A = max(A, (long double)0);
        long double B = chb[k-1];
        long double C = 1+A-B;
        C = max(C, (long double)0);
        
        ld p1l = 0;
        ld p1r = C/2;
        forn(steps,0,200) {
            ld p1m = (p1l+p1r)/2;
            ld q1m = C - p1m;
            if(p1m*q1m > A) p1r = p1m;
            else p1l=p1m;
        }
        
        //long double D = C*C/4. - A;
        //D = max(D,(long double)0.);
        p[k] = C-p1r;//C/2. + sqrt(D);
        q[k] = p1r;//C/2. - sqrt(D);
        if(p[k]-eps > p[k-1] || q[k]-eps > q[k-1]) swap(p[k], q[k]);
    }
    p.pb(0);
    q.pb(0);
    forn(i,1,n+1) printf("%.24lf ", (double)max(-p[i+1] + p[i],(long double)0.)); printf("\n");
    forn(i,1,n+1) printf("%.24lf ", (double)max(-q[i+1] + q[i],(long double)0.)); printf("\n");
    
    
}