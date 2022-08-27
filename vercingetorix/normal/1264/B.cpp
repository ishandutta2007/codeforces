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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int a1=a,b1=b,c1=c,d1=d;
    int c0 = 0;
    while(a1>2) {
        a1--;b1--;
        c0++;
    }
    int c3 = 0;
    while(d1>2) {
        d1--;c1--;
        c3++;
    }
    if(c0>0 && b1<=0) {
        cout<<"NO";
        return 0;
    }
    if(c3>0 && c1<=0) {
        cout<<"NO";
        return 0;
    }
    int c12 = 0;
    while(b1>4) {
        b1--; c1--;
        c12 ++;
    }
    while(c1 > 4) {
        b1--; c1--;
        c12++;
    }
    if(c1<0 || b1 < 0) {
        cout<<"NO";
        return 0;
    }
    
    vi x,xi;
    forn(i,0,a1) x.pb(0);
    forn(i,0,b1) x.pb(1);
    forn(i,0,c1) x.pb(2);
    forn(i,0,d1) x.pb(3);
    forn(i,0,a1+b1+c1+d1) xi.pb(i);
    do {
        int can =1;
        forn(i,1,x.size()) {
            if(abs(x[xi[i]] - x[xi[i-1]]) != 1) {
                can = 0;
                break;
            }
        }
        if(can) {
            printf("YES\n");
            for(auto si : xi) {
                int s = x[si];
                printf(" %d", s);
                if(s==1) {
                    while(c0>0) {
                        c0--;
                        printf(" 0 1");
                    }
                    while(c12>0) {
                        c12--;
                        printf(" 2");
                        while(c3>0) {
                            c3--;
                            printf(" 3 2");
                        }
                        while(c12>0) {
                            c12--;
                            printf(" 1");
                            printf(" 2");
                        }
                        printf(" 1");
                    }
                }
                if(s==2) {
                    while(c3>0) {
                        c3--;
                        printf(" 3 2");
                    }
                    while(c12>0) {
                        c12--;
                        printf(" 1");
                        while(c0>0) {
                            c0--;
                            printf(" 0 1");
                        }
                        while(c12>0) {
                            c12--;
                            printf(" 2 1");
                        }
                        printf(" 2");
                    }
                }
                
            }
            return 0;
            
        }
    } while(std::next_permutation(all(xi)));
    cout<<"NO";
}