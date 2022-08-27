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
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int cur = -100000000;
    int bx,by;
//    int by;
    int A = 0;
    std::mt19937_64 gen (24986);
    forn(i,0,500) {
        int cx = gen()%(200000001) - 100000000;
        int cy = gen()%(200000001) - 100000000;
        printf("0 %d %d\n", cx, cy);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if(res>=A) {
            A=res;
            bx = cx;
            by = cy;
        }
//        cur+=10000;
    }
//    if(bx==900000000) {
//        cout<<"ejgbewkjgbewkjbg";
//        return 0;
//    }
    int cury = -100000000;
    vi ansy,ansx;
    while(1) {
        printf("0 %d %d\n", bx, cury);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if(res==-1) {
            cout << 'f'<<1;
            return 0;
        }
        if(res < A) {
            cury += res;
            break;
        }
        cury+=A;
    }
    ansy.pb(cury);
    int last = cury;
    cury++;
    while(1) {
        if(cury > 100000000) break;
        printf("0 %d %d\n", bx, cury);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if(res==-1) {
            cout << 'f'<<2;
            return 0;
        }
        if(res<min(A,cury-last)) {
            cury+=res;
            ansy.pb(cury);
            last=cury;
            
            if(cury+32<=100000000) {
                printf("0 %d %d\n", bx, cury+32);
                fflush(stdout);
                scanf("%d", &res);
                if(res==32) cury+=31;
            }
            cury++;
            
        }
        else {
            cury = min(2*cury-last,cury+A);
        }
    }
    
    cury = -100000000;
    while(1) {
        printf("0 %d %d\n", cury, by);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if(res==-1) {
            cout << 'f'<<3;
            return 0;
        }
        if(res < A) {
            cury += res;
            break;
        }
        cury+=A;
    }
    ansx.pb(cury);
    last = cury;
    cury++;
    while(1) {
        if(cury > 100000000) break;
        printf("0 %d %d\n", cury, by);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if(res==-1) {
            cout << 'f'<<4;
            return 0;
        }
        if(res<min(A,cury-last)) {
            cury+=res;
            ansx.pb(cury);
            last=cury;
            if(cury+32<=100000000) {
                printf("0 %d %d\n", cury+32, by);
                fflush(stdout);
                scanf("%d", &res);
                if(res==32) cury+=31;
            }
            cury++;
        }
        else {
            cury = min(2*cury-last,cury+A);
        }
    }
    printf("1 %d %d\n", (int)ansx.size(), (int)ansy.size());
    for(auto x : ansx) printf("%d ", x);
    printf("\n");
    for(auto x : ansy) printf("%d ", x);
    printf("\n");
    fflush(stdout);
    
    
}