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
    int n;
    scanf("%d", &n);
    vi p(n);
    vi b(n);
    forn(i,0,n) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    forn(i,0,n) scanf("%d", &b[i]);
    vi used(n,0);
    int cnt = 0;
    int sum = 0;
    forn(i,0,n) {
        sum += b[i];
        if(!used[i]) {
            int cur = i;
            cnt++;
            while(1) {
                cur = p[cur];
                used[cur] = 1;
                if(cur==i) break;
            }
        }
    }
    if(cnt == 1) cnt=0;
    if(sum%2==0) cnt++;
    cout<<cnt;
}