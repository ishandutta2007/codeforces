#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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

long long mod=1000000007;

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
    int n,m,k;
    //string s;
    ll ans = 0;
    //cin >> n;
    //vi a(n);
    //forn(i,0,n) cin>>a[i];
    //cout<<ans;
    vector<char> x(8);
    forn(i,0,8) cin>>x[i];
    string s1, s2;
    forn(i,0,4) s1.pb(x[i]);
    forn(i,4,8) s2.pb(x[i]);
    swap(s1[3],s1[2]);
        swap(s2[3],s2[2]);
    string sn1,sn2;
    int a1=0, a2=0;
    while(s1[a1]!='A') a1++;
    while(s2[a2]!='A') a2++;
    string ss1, ss2;
    forn(i,0,4) {
        char y = s1[(a1+i)%4];
        if(y!='X') ss1.pb(y);
        
        char y2 = s2[(a2+i)%4];
        if(y2!='X') ss2.pb(y2);
    }
    if(ss1==ss2) cout<<"YES";
    else cout<<"NO";
}