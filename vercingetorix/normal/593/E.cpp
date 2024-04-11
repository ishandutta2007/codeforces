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

vvll mprod(vvll &a, vvll &b) {
    int n = a.size();
    vvll c(n, vll(n,0));
    forn(i,0,n) {
        forn(j,0,n) {
            forn(k,0,n) {
                c[i][j] += a[i][k] * b[k][j];
                if(k==6 || k== 12 || k==16) c[i][j] = c[i][j]%mod;
            }
            c[i][j] = c[i][j] % mod;
        }
    }
    return c;
}

vvll mexp(vvll & a, int d) {
    int n = a.size();
    vvll res(n, vll(n,0));
    vvll md = a;
    forn(i,0,n) res[i][i] = 1;
    while(d>0) {
        if(d%2) {
            res = mprod(res, md);
        }
        d /= 2;
        md = mprod(md, md);
    }
    return res;
}

vll newpos(vvll & a, vll & pos) {
    int n = a.size();
    vll nepos(n, 0);
    forn(i,0,n) {
        forn(j,0,n) {
            nepos[i] = (nepos[i] + a[i][j] * pos[j]) % mod;
        }
    }
    return nepos;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    vll pos(n*m, 0);
    pos[0] = 1;
    int curt = 1;
    vi occ(m*n, 0);
    vvll per(n*m, vll(n*m, 0));
    forn(i,0,m*n) per[i][i] = 1;
    forn(i,0,n) {
        forn(j,0,m) {
            if(j>0) per[i*m+j][i*m+j-1] = 1;
            if(j<m-1) per[i*m+j][i*m+j+1] = 1;
            if(i>0) per[i*m+j][i*m+j-m] = 1;
            if(i<n-1) per[i*m+j][i*m+j+m] = 1;
        }
    }
    forn(i,0,q) {
        int tp,x,y,t;
        scanf("%d %d %d %d", &tp, &x, &y, &t);
        x--;
        y--;
        
        if(tp == 1) {
            vvll mdeg = mexp(per, t - curt);
            pos = newpos(mdeg, pos);
            printf("%lld\n", pos[x*m+y]);
        }
        else if(tp==2) {
            vvll mdeg = mexp(per, t - curt-1);
            pos = newpos(mdeg, pos);

            
            if(y>0) {
                per[x*m+y][x*m+y-1] = 0;
            }
            if(y<m-1) {
                per[x*m+y][x*m+y+1] = 0;
            }
            if(x>0) {
                per[x*m+y][x*m+y-m] = 0;
            }
            if(x<n-1) {
                per[x*m+y][x*m+y+m] = 0;
            }
            per[x*m+y][x*m+y] = 0;
            pos = newpos(per, pos);
//            
//            if(y>0) {
//                per[x*m+y-1][x*m+y] = 0;
//            }
//            if(y<m-1) {
//                per[x*m+y+1][x*m+y] = 0;
//            }
//            if(x>0) {
//                per[x*m+y-m][x*m+y] = 0;
//            }
//            if(x<n-1) {
//                per[x*m+y+m][x*m+y] = 0;
//            }
            
//            forn(ii,0,n) {
//                forn(jj,0,m) {
//                    cout << pos[ii*m + jj] << " ";
//                }
//                cout<<endl;
//            } cout<<endl;
        }
        else if(tp==3) {
            vvll mdeg = mexp(per, t - curt);
            pos = newpos(mdeg, pos);
            if(y>0) {
                per[x*m+y][x*m+y-1] = 1;
//                per[x*m+y-1][x*m+y] = 1;
            }
            if(y<m-1) {
                per[x*m+y][x*m+y+1] = 1;
//                per[x*m+y+1][x*m+y] = 1;
            }
            if(x>0) {
                per[x*m+y][x*m+y-m] = 1;
//                per[x*m+y-m][x*m+y] = 1;
            }
            if(x<n-1) {
                per[x*m+y][x*m+y+m] = 1;
//                per[x*m+y+m][x*m+y] = 1;
            }
            per[x*m+y][x*m+y] = 1;
        }
        
        
        curt = t;
    }
    
}