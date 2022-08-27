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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
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
    int os = 0;
    int es = 0;
    int t;
    forn(i,0,q) {
        scanf("%d", &t);
        if(t == 2) {
            if(os%2 != 0) os--;
            else os++;
            if(es%2 != 0) es++;
            else es--;
        }
        else {
            int sh;
            scanf("%d", &sh);
            os += sh;
            es += sh;
        }
        es=(es+n)%n;
        os=(os+n)%n;
    }
    vi ans(n+1);
    forn(i,1,n+1) {
        if(i%2) ans[(i+os-1)%n + 1] = i;
        else ans[(i+es-1)%n + 1] = i;
    }
    forn(i,1,n+1) printf("%d ", ans[i]);
    
    
}