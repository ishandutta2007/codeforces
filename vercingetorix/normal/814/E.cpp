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

ll d[50][50][50];
vvll cnk(51, vll(51, 0));
vvll spo(51, vll(51,0));

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    spo[0][0] = 1;
    forn(j,0,51) forn(i,0,51)  {
        if(i%2==1) continue;
        if(i>=1) {
            spo[i][j] = (ll(i-1)*spo[i-2][j] + ll(j)*spo[i][j-1])%mod;
        }
        else {
            if(j<=2) continue;
            spo[i][j] = ((ll)((j-1)*(j-2)/2) * spo[2][j-3])%mod;
        }
    }
    
    forn(i,0,51) cnk[i][0] = 1;
    forn(i,1,51) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    vll nfac(1,1);
    forn(i,1,100) {
        nfac.pb((nfac.back() * (ll)i)%mod);
    }
    int n;
    cin>>n;
    vi c(n);
    forn(i,0,n) cin>>c[i];
    d[n-1][0][0] = 1;
    for(int s = n-2; s >= 0; s--) {
        // find d[s][c1][c2]
        forn(c1,0,51) {
            if(s + c1 >= n) break;
            forn(c2,0,51) {
                if(c1+c2==0) continue;
                if(s+c1+2*c2 >= n) break;
                ll sp = nfac[c1+2*c2];
                forn(i,0,c2) sp = (sp * (mod+1)/2) % mod;
                int nc1=0, nc2=0;
                forn(i,s+1,s+c1+2*c2+1) {
                    if(c[i] == 2) nc1++;
                    else nc2++;
                }
                int ns = s+c1+2*c2;
                forn(pc1,0,nc1+1) {
                    forn(pc21,0,nc2+1) {
                        int nss = ns + pc1+pc21;
                        if(nss >= n) break;
                        forn(pc2,0,min(nc2+1-pc21,1+(n-nss)/2)) {
                            int nsss = nss + 2*pc2;
                            if(nsss>=n) continue;
                            // t = nss + pc2
                            ll cnew = d[ns][pc1+pc21][pc2];
                            cnew = (cnew * cnk[nc1][pc1])%mod;
                            cnew = (cnew * cnk[nc2][pc21])%mod;
                            cnew = (cnew * cnk[nc2-pc21][pc2])%mod;
                            cnew = (cnew * spo[nc1-pc1+pc21][nc2-pc2-pc21]) % mod;
                            d[s][c1][c2] = (d[s][c1][c2] + sp*cnew)%mod;
                        }
                    }
                }
                
            }
            
        }
    }
    if(c[0] == 2) {
        cout<<d[0][0][1];
    }
    else {
        vi u;
        if(n<=3) {
            cout<<0;
            return 0;
        }
        vi c2nt(4,0);
        forn(i,1,4) c2nt[c[i]-1]++;
        if(c2nt[1] == 3) {
            cout << (d[3][3][0] + 3*d[3][1][0])%mod;
        }
        else if(c2nt[1] == 2) {
            cout << (d[3][2][1] + d[3][0][1] + 2*d[3][2][0] + d[3][0][0]) %mod;
        }
        else if(c2nt[1] == 1) {
            cout << (d[3][1][2] + d[3][3][0] + 2*d[3][1][1] + 2*d[3][1][0])%mod;
        }
        else if(c2nt[1] == 0) {
            cout << (d[3][0][3] + 3*d[3][2][1] + 3*d[3][2][0] + d[3][0][0])%mod;
        }
        
        
    }
    
}