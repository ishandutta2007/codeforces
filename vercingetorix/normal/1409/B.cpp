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

ll go(int a, int b, int x, int y, int n) {
    int dec = min(a-x, n);
    a-=dec;
    n-=dec;
    if(a==x) {
        b -= min(n,b-y);
    }
    return ll(a)*ll(b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int a,b,x,y,n;
        scanf("%d %d %d %d %d", &a,&b,&x,&y,&n);
//        if(a>b) {
//            swap(a,b);
//            swap(x,y);
//        }
        
//        forn(sg,0,10) {
//            if(a==b) {
//                int dec = min(a-x, b-y);
//                dec = min(dec,n/2);
//                a-=dec;
//                b-=dec;
//                n-=dec*2;
//                if(a==x) {
//                    dec=  min(b-y,n);
//                    b-=dec;
//                    n-=dec;
//                }
//                else if(b==y) {
//                    dec=  min(a-x,n);
//                    a-=dec;
//                    n-=dec;
//                }
//                else if(n==1) {
//                    a--;
//                    n = 0;
//                }
//            }
//            if(a>b) {
//                swap(a,b);
//                swap(x,y);
//            }
//            int dec = min(b-a, n);
//            dec = min(dec, b-y);
//            b-=dec;
//            n-=dec;
//        }
        cout<<min(go(a,b,x,y,n), go(b,a,y,x,n))<<endl;
    }
    
}