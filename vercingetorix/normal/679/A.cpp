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
//fflush(stdout)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    vi p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    //cout<<p.size();
    int cnt = 0;
    for(auto u : p) {
        if(cnt>=2) {
            printf("composite\n");
            return 0;
        }
        printf("%d\n", u);
        fflush(stdout);
        string s;
        cin>>s;
        if(s == "yes") {
            cnt++;
            if(u*u > 100) continue;
            printf("%d\n", u*u);
            fflush(stdout);
            string s;
            cin>>s;
            if(s=="yes") cnt++;
        }
    }
    if(cnt>=2) {
        printf("composite\n");
        return 0;
    }
    printf("prime\n");
    return 0;
}