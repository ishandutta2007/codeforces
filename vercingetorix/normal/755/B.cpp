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
    int n,m;
    scanf("%d %d\n", &n, &m);
    set<string> a;
    string s;
    int n1 = 0;
    int n2 = 0;
    int n0 = 0;
    forn(i,0,n) {
        getline(cin, s);
        n1++;
        a.insert(s);
    }
    forn(i,0,m) {
        getline(cin, s);
        if(a.find(s) == a.end()) n2++;
        else {
            n1--;
            n0++;
        }
    }
    if(n0%2==0) {
        if(n1>n2) cout<<"YES";
        else cout<<"NO";
    }
    else {
        if(n1>=n2) cout<<"YES";
        else cout<<"NO";
    }
    
}