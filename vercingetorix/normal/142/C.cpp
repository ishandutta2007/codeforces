#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
vs ans;
int n,m;

void go() {
    vs ans2(m, string(n, '.'));
    forn(i,0,m) forn(j,0,n) ans2[i][j] = ans[j][i];
    ans = ans2;
    swap(n,m);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int flip = 0;
    cin>>n>>m;
    if(n>m) {
        swap(m,n);
        flip = 1;
    }
    ans = vs(n, string(m, '.'));
    int num = 0;
    if(n==3) {
        for(int j = 0; j +2 <m; j+=4) {
            ans[0][j] = 'A' + num;
            ans[0][j+1] = 'A' + num;
            ans[0][j+2] = 'A' + num;
            ans[1][j+1] = 'A' + num;
            ans[2][j+1] = 'A' + num;
            num++;
        }
        for(int j = 2; j +2 <m; j+=4) {
            ans[2][j] = 'A' + num;
            ans[2][j+1] = 'A' + num;
            ans[2][j+2] = 'A' + num;
            ans[0][j+1] = 'A' + num;
            ans[1][j+1] = 'A' + num;
            num++;
        }
    }
    else if(n==4) {
        for(int j = 0; j +2 <m; j+=3) {
            ans[0][j] = 'A' + num;
            ans[0][j+1] = 'A' + num;
            ans[0][j+2] = 'A' + num;
            ans[1][j+1] = 'A' + num;
            ans[2][j+1] = 'A' + num;
            num++;
        }
        for(int j = 1; j +2 <m; j+=3) {
            ans[3][j] = 'A' + num;
            ans[3][j+1] = 'A' + num;
            ans[3][j+2] = 'A' + num;
            ans[1][j+1] = 'A' + num;
            ans[2][j+1] = 'A' + num;
            num++;
        }
    }
    else if(n==5) {
        {
            num = 4;
            ans = {
                "A.BBB",
                "AAAB.",
                "AC.BD",
                ".CDDD",
                "CCC.D"};
            forn(j,0,m-5) forn(i,0,5) ans[i].pb('.');
            if(m>=7) {
                ans[1][4] = 'A' + num;
                ans[1][5] = 'A' + num;
                ans[1][6] = 'A' + num;
                ans[2][5] = 'A' + num;
                ans[3][5] = 'A' + num;
                num++;
            }
            if(m>=8) {
                ans[4][5] = 'A' + num;
                ans[4][6] = 'A' + num;
                ans[4][7] = 'A' + num;
                ans[3][6] = 'A' + num;
                ans[2][6] = 'A' + num;
                num++;
            }
            if(m>=9) {
                ans[0][8] = 'A' + num;
                ans[0][6] = 'A' + num;
                ans[0][7] = 'A' + num;
                ans[1][7] = 'A' + num;
                ans[2][7] = 'A' + num;
                num++;
            }
            
        }
    }
    else if(n==6) {
        if(m==6) {
            num = 5;
            ans = {
                "AAAB..",
                ".ACBBB",
                ".ACBE.",
                "DCCCE.",
                "DDDEEE",
                "D....."};
            
        }
        else if(m == 7) {
            num = 6;
            ans = {
                "A.BBB.C",
                "AAABCCC",
                "A..B..C",
                "F.EEE.D",
                "FFFEDDD",
                "F..E..D"};
        }
        else if(m == 8) {
            num = 7;
            ans = {
                "A.BBB..C",
                "AAAB.CCC",
                "A..BG..C",
                "F..EGGGD",
                "FFFEGDDD",
                "F.EEE..D"};
        }
        else {
            for(int j = 0; j +2 <m; j+=4) {
                ans[0][j] = 'A' + num;
                ans[0][j+1] = 'A' + num;
                ans[0][j+2] = 'A' + num;
                ans[1][j+1] = 'A' + num;
                ans[2][j+1] = 'A' + num;
                num++;
            }
            for(int j = 2; j +2 <m; j+=4) {
                ans[2][j] = 'A' + num;
                ans[2][j+1] = 'A' + num;
                ans[2][j+2] = 'A' + num;
                ans[0][j+1] = 'A' + num;
                ans[1][j+1] = 'A' + num;
                num++;
            }
            for(int j = 0; j +2 <m; j+=4) {
                ans[3][j] = 'A' + num;
                ans[3][j+1] = 'A' + num;
                ans[3][j+2] = 'A' + num;
                ans[4][j+1] = 'A' + num;
                ans[5][j+1] = 'A' + num;
                num++;
            }
            for(int j = 2; j +2 <m; j+=4) {
                ans[5][j] = 'A' + num;
                ans[5][j+1] = 'A' + num;
                ans[5][j+2] = 'A' + num;
                ans[3][j+1] = 'A' + num;
                ans[4][j+1] = 'A' + num;
                num++;
            }
        }
    }
    else if(n==7) {
        if(m != 8 ) {
            num = 8;
            ans = {
                "AAABCCC",
                ".A.B.C.",
                "DABBBCE",
                "DDD.EEE",
                "DGHHHFE",
                ".G.H.F.",
                "GGGHFFF"};
            forn(j,0,m-7) forn(i,0,7) ans[i].pb('.');
            if(m == 9) {
                ans[1][6] = 'A' + num;
                ans[1][7] = 'A' + num;
                ans[1][8] = 'A' + num;
                ans[0][8] = 'A' + num;
                ans[2][8] = 'A' + num;
                num++;
                ans[5][6] = 'A' + num;
                ans[5][7] = 'A' + num;
                ans[5][8] = 'A' + num;
                ans[6][8] = 'A' + num;
                ans[4][8] = 'A' + num;
                num++;
            }
        }
        else {
            num = 9;
            ans = {
                "AAA.III.",
                ".AHHHIG.",
                ".ABH.IG.",
                "BBBHEGGG",
                "C.BDEEEF",
                "CCCDEFFF",
                "C.DDD..F"
            };
        }
        
    }
    else if(n==8) {
        if(m ==8) {
            num = 10;
            ans = {
                "A..IHHH.",
                "AAAI.HG.",
                "A.IIIHG.",
                "B.JJJGGG",
                "BBBJFFF.",
                "BC.JDFE.",
                ".CDDDFE.",
                "CCC.DEEE"
            };
        }
        if(m== 9) {
            num = 12;
            ans = {
                "..ABBB..C",
                "AAAEBFCCC",
                ".DAEBFFFC",
                ".DEEEFGGG",
                "DDDHJJJG.",
                "IHHHKJLG.",
                "IIIHKJLLL",
                "I..KKKL.."
            };
        }
    }
    else if(n==9) {
        num = 13;
        ans = {
            "AAAK..LLL",
            ".ABKKKML.",
            ".ABKJ.ML.",
            "CBBBJMMMI",
            "CCCJJJIII",
            "C..H.G..I",
            "DHHHEGGGF",
            "DDDHEGFFF",
            "D..EEE..F"
        };
    }
    
    if(flip) go();
    cout<<num<<'\n';
    forn(i,0,n) cout<<ans[i]<<'\n';
    
    
}