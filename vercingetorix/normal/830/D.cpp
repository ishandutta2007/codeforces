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
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
ll d[401][401];
ll cnk[501][501];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvll cnk(501, vll(501, 0));
    forn(i,0,501) cnk[i][0] = 1;
    forn(i,1,501) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }

    int n;
    cin>>n;
    forn(i,0,401) d[i][0] = 1;
    d[1][1] = 1;
    forn(k,2,401) {
        forn(l,1,401) {
            // A  
            forn(nl,0,l+1) {
                d[k][l] = (d[k][l] + (d[k-1][nl]*d[k-1][l-nl])%mod * cnk[l][nl]) % mod;
            }
//            // A  
//            forn(nl,0,l) {
//                d[k][l] = (d[k][l] + (d[k-1][nl]*d[k-1][l-1-nl])%mod * ((l*cnk[l-1][nl]) % mod)) % mod;
//            }
//            // A   
//            forn(nl,0,l+1) {
//                d[k][l] = (d[k][l] + (d[k-1][nl]*d[k-1][l-nl])%mod * ((2*l*cnk[l][nl]) % mod)) % mod;
//            }
//            // A  2  
//            forn(nl,1,l+1) {
//                d[k][l] = (d[k][l] + (d[k-1][nl]*d[k-1][l+1-nl])%mod * ((2*l*cnk[l-1][nl-1]) % mod)) % mod;
//            }
//            // A  2  
//            forn(nl,2,l+2) {
//                d[k][l] = (d[k][l] + (d[k-1][nl]*d[k-1][l+1-nl])%mod * ((2*l*cnk[l-1][nl-2]) % mod)) % mod;
//            }
            forn(nl,0,l+2) {
                ll dl = (d[k-1][nl]*l)%mod;
                ll mn = 0;
                if(nl < l) mn += d[k-1][l-1-nl] * cnk[l-1][nl];
                if(nl < l+1) mn += d[k-1][l-nl] * 2*cnk[l][nl];
                if(nl>0 && nl<l+1) mn+=d[k-1][l+1-nl] * 2*cnk[l-1][nl-1];
                if(nl > 1) mn+=d[k-1][l+1-nl] * 2*cnk[l-1][nl-2];
                mn = mn%mod;
                d[k][l] = (d[k][l] + mn*dl)%mod;
            }
        }
    }
    cout<<d[n][1];
    
}