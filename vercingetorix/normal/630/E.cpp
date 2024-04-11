#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    ll ans = 0;
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(abs(x1-y1)%2 == 1) {
        y1++;
        y2++;
    }
    //cout<<ro*co + re*ce;
    ll h = (y2-y1+1)*(x2-x1+1);
    ans = (h)/2;
    if (((h%2)==1) && (abs(x1-y1)%2 == 0)) ans++;
    //if ((x2-x1%2)%2 == 0) if ((y2-y1%2)%2 == 0) if(abs(x1-y1%2)%2 == 0) ans++;
    cout<<ans;
}