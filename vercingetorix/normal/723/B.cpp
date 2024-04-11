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
    string s;
    int n;
    scanf("%d\n", &n);
    getline(cin, s);
    int cur = 0;
    int c = 0;
    int a= 0;
    int b=0;
    forn(i,0,n) {
        if(s[i] == '(' || s[i] ==')' || s[i] == '_') {
            if(c>0) {
                if(cur > 0) b++;
                else a=max(a,c);
                c = 0;
            }
            if(s[i] == '(') cur++;
            if(s[i] == ')') cur--;
        }
        else {
            c++;
        }
    }
    if(c>0) a=max(a,c);
    cout<<a<<' '<<b;
}