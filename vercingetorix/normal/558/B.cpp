#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k;
    vvi a(1000001);
    cin>>n;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        a[x].pb(i);
    }
    int maxnum=0;
    int l=0,r=9999999;
    for(int i=1; i<1000001; i++) {
        sort(all(a[i]));
        if(a[i].size()>maxnum) maxnum=a[i].size();
    }
    for(int i=1; i<1000001; i++) {
        int x=a[i].size();
        if(x<maxnum) continue;
        if(a[i][x-1]-a[i][0]<r-l) {
            r=a[i][x-1];
            l=a[i][0];
        }
    }
    cout<<l+1<< ' '<<r+1;
}