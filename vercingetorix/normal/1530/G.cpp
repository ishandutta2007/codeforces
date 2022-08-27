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

const int mod = 31607;
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
string a,b;
vpi qa, qb;
int sw = 0;

void swa() {
    swap(qa,qb);
    swap(a,b);
    sw = 1-sw;
}

void goa(int l, int r) {
    qa.pb(mp(l,r));
    for(int i = 0; l+i<r-i;i++) swap(a[l+i], a[r-i]);
}
void gob(int l, int r) {
    qb.pb(mp(l,r));
    for(int i = 0; l+i<r-i;i++) swap(b[l+i], b[r-i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[10050];
    while(t--) {
        int n,k;
        sw= 0;
        qa.clear();
        qb.clear();
        scanf("%d %d\n", &n, &k);
        scanf("%s", c);
        a = string(c);
        scanf("%s", c);
        b = string(c);
        int ca = 0;
        forn(i,0,n) if(a[i]=='1') ca++;
        int cb = 0;
        forn(i,0,n) if(b[i]=='1') cb++;
        if(a==b) {
            printf("0\n");
            continue;
        }
        if(ca!=cb || ca < k || k==0) {
            printf("-1\n");
            continue;
        }
        
        while(ca>k+1) {
            int ra = n-1;
            int rb = n-1;
            while(a[ra]!='1') ra--;
            while(b[rb]!='1') rb--;
            if(ra > rb) {
                swap(ra,rb);
                swa();
            }
            int cnt = 1;
            int la= ra;
            while(cnt!=k) {
                la--;
                if(a[la] == '1') cnt++;
            }
            goa(la,rb);
            ca--;
            cb--;
            n = rb;
        }
        if(ca == k) {
            int ra = n-1;
            int rb = n-1;
            while(a[ra]!='1') ra--;
            while(b[rb]!='1') rb--;
            goa(0, ra);
            gob(0, rb);
            if(a!=b) {
                ra = n-1;
                rb = n-1;
                while(a[ra]!='1') ra--;
                while(b[rb]!='1') rb--;
                if(ra!=rb) {
                    printf("-1\n");
                    continue;
                }
                goa(0,ra);
                if(a!=b) {
                    printf("-1\n");
                    continue;
                }
            }
        }
        else {
            int l = 0;
            int r = n-1;
            forn(i,0,k) {
                while(a[l] != '1') l++;
                while(a[r] != '1') r--;
                if(i%2==0) goa(l+1,r);
                else goa(l,r-1);
            }
            l = 0;
            r = n-1;
            forn(i,0,k) {
                while(b[l] != '1') l++;
                while(b[r] != '1') r--;
                if(i%2==0) gob(l+1,r);
                else gob(l,r-1);
            }
            
            int la = 0;
            int lb = 0;
            while(a[la]!='1') la++;
            while(b[lb]!='1') lb++;
            if(la != lb) {
                if(la>lb) {
                    swa();
                    swap(la,lb);
                }
                if(k%2 == 1) {
                    forn(i,0,k+1) {
                        if(i%2==0) gob(la,lb+k-1);
                        else gob(la+1,lb+k);
                    }
                }
                else if(a!=b) {
                    printf("-1\n");
                    continue;
                }
            }
        }
        
        if(sw) swap(qa,qb);
        reverse(all(qb));
        for(auto x : qb) qa.pb(x);
        printf("%d\n", qa.size());
        for(auto x : qa) printf("%d %d\n", x.first+1, x.second+1);
    }
    
    
}