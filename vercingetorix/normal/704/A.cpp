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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    int del = 0;
    deque<int> a;
    vector<deque<int>> unread(n);
    int ans = 0;
    int tot = 0;
    forn(i,0,q) {
        int tp, t;
        scanf("%d %d", &tp, &t);
        if(tp==1) {
            a.pb(t);
            unread[t-1].pb(tot);
            tot++;
            ans++;
        }
        else if(tp==2) {
            ans -= (int)unread[t-1].size();
            unread[t-1].clear();
        }
        else if(tp==3) {
            while(del<t) {
                int x = a.front();
                if(unread[x-1].size() > 0 && unread[x-1].front() == del) {
                    unread[x-1].pop_front();
                    ans--;
                }
                a.pop_front();
                del++;
            }
        }
        printf("%d\n", ans);
    }
    
    
    
    
}