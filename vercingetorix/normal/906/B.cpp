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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m ;
    scanf("%d %d", &n, &m);
//    forn(n,3,6) forn(m,3,6) {
    vvi a(n, vi(m));
    int cnt = 1;
    int mn = 0;
    forn(i,0,n) forn(j,0,m) a[i][j] = cnt++;
    if(n > m) {
        vvi b(m, vi(n));
        forn(i,0,n) forn(j,0,m) b[j][i] = a[i][j];
        mn = 1;
        a=b;
        swap(m, n);
    }
    
    if(m>=4) {
        if(m%2==0) {
            forn(i,0,n) {
                vi was = a[i];
                forn(j,0,m/2) a[i][j] = was[m-2-2*j];
                forn(j,0,m/2) a[i][j+m/2] = was[m-1-2*j];
                if(i%2) reverse(all(a[i]));
            }
        }
        else {
            forn(i,0,n) {
                vi was = a[i];
                forn(j,0,m/2+1) a[i][j+(i%2)*(m/2)] = was[m-1-2*j];
                forn(j,0,m/2) a[i][j + (1-i%2)*(m/2+1)] = was[m-2-2*j];
            }
        }
    }
    else if(m == 3) {
        if(n<=2) {
            cout<<"NO";
            return 0;
        }
        else if(n==3) {
            vi res({2,8,1,4,3,5,6,7,9});
            cnt = 0;
            forn(i,0,n) forn(j,0,m) a[i][j] = res[cnt++];
        }
    }
    else if(m==2) {
        cout<<"NO";
        return 0;
    }
    if(mn) {
        vvi b(m, vi(n));
        forn(i,0,n) forn(j,0,m) b[j][i] = a[i][j];
        mn = 0;
        a = b;
        swap(m, n);
    }
//        forn(i,0,n) forn(j,0,m-1) if(abs(a[i][j]-a[i][j+1]) == m) {
//            cout<<"AWOFNAOWFNQWF";
//            exit(0);
//        }
//        forn(i,0,n-1) forn(j,0,m) if(abs(a[i+1][j]-a[i][j]) == m) {
//            cout<<"AWOFNAOWFNQWF";
//            exit(0);
//        }
//        forn(i,0,n) forn(j,0,m-1) if(abs(a[i][j]-a[i][j+1]) == 1 && min(a[i][j],a[i][j+1])%m !=0 ) {
//            cout<<"AWOFNAOWFNQWF";
//            exit(0);
//        }
//        forn(i,0,n-1) forn(j,0,m) if(abs(a[i+1][j]-a[i][j]) == 1 && min(a[i+1][j],a[i][j])%m != 0) {
//            cout<<"AWOFNAOWFNQWF";
//            exit(0);
//        }
    printf("YES\n");
    forn(i,0,n) {
        forn(j,0,m) printf("%d ", a[i][j]);
        printf("\n");
    }
//    }
    
}