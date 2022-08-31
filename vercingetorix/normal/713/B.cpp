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

int n;

vi findone(int x1, int y1, int x2, int y2) {
    vi ans;
    forn(i,0,4) {
        int l,r;
        if(i==0) {
            l=x1;
            r=x2+1;
        }
        else if(i==1) {
            l=y1;
            r=y2+1;
        }
        else if(i==2) {
            l=x1-1;
            r=x2;
        }
        else if(i==3){
            l=y1-1;
            r=y2;
        }
        while(r-l > 1) {
            int m = (r+l)/2;
            if(i>=2) m = (r+l+1)/2;
            if (i==0) printf("? %d %d %d %d\n", m, y1, x2, y2);
            else if (i==1) printf("? %d %d %d %d\n", x1, m, x2, y2);
            else if (i==2) printf("? %d %d %d %d\n", x1, y1, m, y2);
            else if (i==3) printf("? %d %d %d %d\n", x1, y1, x2, m);
            fflush(stdout);
            int c;
            scanf("%d", &c);
            if(i<2) {
                if(c > 0) l=m;
                else r=m;
            }
            else {
                if(c > 0) r=m;
                else l=m;
            }
            fflush(stdout);
            cout.flush();
        }
        if(i<2) ans.pb(l);
        else ans.pb(r);
    }
    return ans;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    
    scanf("%d", &n);
    int l = 0;
    int r = n;
    int c;
    vi ans1, ans2;
    while(r-l > 1) {
        int m = (r+l)/2;
        printf("? 1 1 %d %d\n", m, n);
        fflush(stdout);
        cout.flush();
        scanf("%d", &c);
        if(c > 0) r=m;
        else l=m;
    }
    if(r<n) {
        printf("? %d 1 %d %d\n", r+1, n, n);
        cout.flush();
        fflush(stdout);
        scanf("%d", &c);
        if(c>0) {
            ans1=findone(1, 1, r, n);
            ans2=findone(r+1, 1, n, n);
            printf("! %d %d %d %d %d %d %d %d\n", ans1[0], ans1[1], ans1[2], ans1[3], ans2[0], ans2[1], ans2[2], ans2[3]);
            fflush(stdout);
            cout.flush();
            return 0;
        }
    }
    l = 0;
    r = n;
    while(r-l > 1) {
        int m = (r+l)/2;
        printf("? 1 1 %d %d\n", n, m);
        
        fflush(stdout);
        cout.flush();
        
        scanf("%d", &c);
        if(c > 0) r=m;
        else l=m;
    }
    ans1=findone(1, 1, n, r);
    ans2=findone(1, r+1, n, n);
    printf("! %d %d %d %d %d %d %d %d\n", ans1[0], ans1[1], ans1[2], ans1[3], ans2[0], ans2[1], ans2[2], ans2[3]);
    fflush(stdout);
    cout.flush();
    return 0;
    
    
}