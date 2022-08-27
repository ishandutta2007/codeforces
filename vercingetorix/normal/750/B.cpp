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
    scanf("%d\n", &n);
    int cur = 0;
    forn(i,0,n) {
        char c[10];
        int x;
        scanf("%d %s\n", &x, c);
        string s(c);
        if(s=="South") {
            cur += x;
        }
        else if(s=="North") {
            cur-=x;
        }
        else {
            if(cur==0 || cur==20000) {
                cout<<"NO";
                return 0;
            }
        }
        if(cur<0 || cur>20000) {
            cout<<"NO";
            return 0;
        }
    }
    if(cur !=0) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    
}