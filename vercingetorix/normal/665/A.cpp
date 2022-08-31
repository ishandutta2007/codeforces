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
    int n, m;
    int a,ta,b,tb;
    cin>>a>>ta;
    cin>>b>>tb;
    string s;
    cin>>s;
    int t= ((int)(s[0]-'0')*10 + (int)(s[1]-'0')) *60+ (int)(s[3]-'0')*10 + (int)(s[4]-'0');
    int tmin = t - tb - 300;
    int tmax = min(t + ta - 1, 1439)-300;
    int ans = tmax/b + 1;
    if(tmin>=0) ans -= (1 + tmin/b);
    cout<<ans;
    
}