#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <cstring>
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
    //int x1,x2,x3,y1,y2,y3;
    vll x(3), y(3);
    cin>>x[0]>>y[0];
    cin>>x[1]>>y[1];
    cin>>x[2]>>y[2];
    if((x[0]==x[1])&&(x[1]==x[2])) cout<<1;
    else     if((y[0]==y[1])&&(y[1]==y[2])) cout<<1;
    else if(((x[0]==x[1])&&((y[2]-y[1])*(y[2]-y[0])>=0))) cout<<2;
     else if(((x[2]==x[1])&&((y[0]-y[1])*(y[0]-y[2])>=0))) cout<<2;
     else if(((x[0]==x[2])&&((y[1]-y[2])*(y[1]-y[0])>=0))) cout<<2;
    
     else if(((y[0]==y[1])&&((x[2]-x[1])*(x[2]-x[0])>=0))) cout<<2;
     else if(((y[2]==y[1])&&((x[0]-x[1])*(x[0]-x[2])>=0))) cout<<2;
     else if(((y[0]==y[2])&&((x[1]-x[2])*(x[1]-x[0])>=0))) cout<<2;
    else cout<<3;
    //cout<<ans;
}