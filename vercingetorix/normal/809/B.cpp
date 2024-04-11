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

int n;
bool req(int a, int b) {
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    char c[4];
    scanf("%s", c);
    string s(c);
    if(s=="TAK") return 0;
    else return 1;
}

int findm(int l, int r) {
    while(r-l > 0) {
        int m = (r+l)/2;
        if(req(m,m+1) == 0) r=m;
        else l = m+1;
    }
    return l;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int k;
    scanf("%d %d", &n, &k);
    int m = findm(1, n);
    int l = 1;
    while(l < m) {
        int lm = (l+m-1)/2;
        if(req(lm,lm+1)==0) {
            printf("2 %d %d\n", m, findm(l,lm));
            fflush(stdout);
            return 0;
        }
        l = lm+1;
    }
    int r = n;
    while (r>m) {
        int rm = (r+m+2)/2;
        if(req(rm,rm-1)==0) {
            printf("2 %d %d\n", m, findm(rm, r));
            fflush(stdout);
            return 0;
        }
        r = rm-1;
    }
}