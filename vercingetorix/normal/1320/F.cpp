#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
typedef std::vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int n,m,k;
int to(int x, int y, int z) {
    return x*m*k + y*k + z;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m, &k);
    vvi r(m, vi(k, 0));
    vvi l(m, vi(k, 0));
    forn(i,0,m) forn(j,0,k) scanf("%d", &l[i][j]);
    forn(i,0,m) forn(j,0,k) scanf("%d", &r[i][j]);
    vvi f(n, vi(k, 0));
    vvi b(n, vi(k, 0));
    forn(i,0,n) forn(j,0,k) scanf("%d", &f[i][j]);
    forn(i,0,n) forn(j,0,k) scanf("%d", &b[i][j]);
    vvi u(n, vi(m, 0));
    vvi d(n, vi(m, 0));
    forn(i,0,n) forn(j,0,m) scanf("%d", &u[i][j]);
    forn(i,0,n) forn(j,0,m) scanf("%d", &d[i][j]);
    vvvi rays(n, vvi(m, vi(k, 0)));
    deque<int> q;
    forn(i,0,n*m*k) q.pb(i);
    vvvi trans(n, vvi(m, vi(k, 0)));
    forn(y,0,m) forn(z,0,k) {
        rays[0][y][z] |= 1;
        rays[n-1][y][z] |= 2;
    }
    forn(x,0,n) forn(z,0,k) {
        rays[x][0][z] |= 4;
        rays[x][m-1][z] |= 8;
    }
    forn(x,0,n) forn(y,0,m) {
        rays[x][y][0] |= 16;
        rays[x][y][k-1] |= 32;
    }
    int can = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        int z = v%k;
        int y = v/k % m;
        int x = v/k/m;
        if(trans[x][y][z]) continue;
        vi rv;
        if(rays[x][y][z] & 1) rv.pb(l[y][z]);
        if(rays[x][y][z] & 2) rv.pb(r[y][z]);
        if(rays[x][y][z] & 4) rv.pb(f[x][z]);
        if(rays[x][y][z] & 8) rv.pb(b[x][z]);
        if(rays[x][y][z] & 16) rv.pb(u[x][y]);
        if(rays[x][y][z] & 32) rv.pb(d[x][y]);
        if(rv.empty()) continue;
        int settt = 0;
        if(rv[0] == 0) settt = 1;
        else {
            forn(i,0,(int)rv.size() - 1) if(rv[i] != rv[i+1]) settt = 1;
        }
        if (settt) {
            trans[x][y][z] = 1;
            if(rays[x][y][z] & 1) {
                int nx = x+1;
                while(nx < n && trans[nx][y][z]) nx++;
                if(nx==n && l[y][z] != 0) {
                    can = 0;
                    break;
                }
                if(nx<n) {
                    rays[nx][y][z] |= 1;
                    q.pb(to(nx,y,z));
                }
            }
            if(rays[x][y][z] & 2) {
                int nx = x-1;
                while(nx >= 0 && trans[nx][y][z]) nx--;
                if(nx==-1 && r[y][z] != 0) {
                    can = 0;
                    break;
                }
                if(nx>=0) {
                    rays[nx][y][z] |= 2;
                    q.pb(to(nx,y,z));
                }
            }
            if(rays[x][y][z] & 4) {
                int ny = y+1;
                while(ny < m && trans[x][ny][z]) ny++;
                if(ny==m && f[x][z] != 0) {
                    can = 0;
                    break;
                }
                if(ny<m) {
                    rays[x][ny][z] |= 4;
                    q.pb(to(x,ny,z));
                }
            }
            if(rays[x][y][z] & 8) {
                int ny = y-1;
                while(ny >= 0 && trans[x][ny][z]) ny--;
                if(ny==-1 && b[x][z] != 0) {
                    can = 0;
                    break;
                }
                if(ny>=0) {
                    rays[x][ny][z] |= 8;
                    q.pb(to(x,ny,z));
                }
            }
            if(rays[x][y][z] & 16) {
                int nz = z+1;
                while(nz < k && trans[x][y][nz]) nz++;
                if(nz==k && u[x][y] != 0) {
                    can = 0;
                    break;
                }
                if(nz<k) {
                    rays[x][y][nz] |= 16;
                    q.pb(to(x,y,nz));
                }
            }
            if(rays[x][y][z] & 32) {
                int nz = z-1;
                while(nz >= 0 && trans[x][y][nz]) nz--;
                if(nz==-1 && d[x][y] != 0) {
                    can = 0;
                    break;
                }
                if(nz>=0) {
                    rays[x][y][nz] |= 32;
                    q.pb(to(x,y,nz));
                }
            }
            rays[x][y][z] = 0;
        }
    }
    if(can == 0) {
        printf("-1\n");
    }
    else {
        forn(x,0,n) forn(y,0,m) {
            forn(z,0,k) {
                if(rays[x][y][z] == 0) printf("0 ");
                else if(rays[x][y][z] & 1) printf("%d ", l[y][z]);
                else if(rays[x][y][z] & 2) printf("%d ", r[y][z]);
                else if(rays[x][y][z] & 4) printf("%d ", f[x][z]);
                else if(rays[x][y][z] & 8) printf("%d ", b[x][z]);
                else if(rays[x][y][z] & 16) printf("%d ", u[x][y]);
                else if(rays[x][y][z] & 32) printf("%d ", d[x][y]);
            }
            printf("\n");
            if(y==m-1) printf("\n");
        }
    }
}