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
vi d2;
int sz = 1;
struct vertex{
    int id[2];
    int cnt[2];
};

vertex v[10000000];//10000000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    v[0].id[0]=-1;
    v[0].id[1]=-1;
    v[0].cnt[0]=0;
    v[0].cnt[1]=0;
    d2.pb(1);
    forn(i,0,30) d2.pb(d2.back()*2);
    
    int cur2 = 0;
    for(int j=30; j>=0; j--) {
        int bit=0;
        if(v[cur2].id[bit]==-1) {
            v[cur2].id[bit]=sz;
            v[sz].id[0]=-1;
            v[sz].id[1]=-1;
            v[sz].cnt[0]=0;
            v[sz].cnt[1]=0;
            sz++;
        }
        v[cur2].cnt[bit]++;
        cur2 = v[cur2].id[bit];
    }
    
    int q;
    scanf("%d\n", &q);
    forn(i,0,q) {
        char c;
        int x;
        scanf("%c %d\n", &c, &x);
        if(c=='+') {
            int cur = 0;
            for(int j=30; j>=0; j--) {
                int bit=(x&d2[j])/d2[j];
                if(v[cur].id[bit]==-1) {
                    v[cur].id[bit]=sz;
                    v[sz].id[0]=-1;
                    v[sz].id[1]=-1;
                    v[sz].cnt[0]=0;
                    v[sz].cnt[1]=0;
                    sz++;
                }
                v[cur].cnt[bit]++;
                cur = v[cur].id[bit];
            }
        }
        else if(c=='-') {
            int cur = 0;
            for(int j=30; j>=0; j--) {
                int bit=(x&d2[j])/d2[j];
                v[cur].cnt[bit]--;
                cur = v[cur].id[bit];
            }
        }
        else if(c=='?') {
            int ans = 0;
            int cur = 0;
            for(int j=30; j>=0; j--) {
                int bit=(x&d2[j])/d2[j];
                if(v[cur].cnt[1-bit] >0) {
                    ans|=d2[j];
                    cur =v[cur].id[1-bit];
                }
                else {
                    cur = v[cur].id[bit];
                }
            }
            printf("%d\n", ans);
        }
    }
    
    
}